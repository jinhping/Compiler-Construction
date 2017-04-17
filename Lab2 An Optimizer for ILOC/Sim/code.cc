#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "code.h"
#include <cctype>
#include <unordered_map>

using namespace std;

unordered_map<string, int> label2line;

void ParseInstructions(string filename, vector<instruction> &instructions) {
	ifstream infile;
	infile.open(filename);
	string line = "";
	int line_number = 0;
	while (getline(infile, line)) {
		if (line.find("/") != string::npos) {
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == '/') {
					line = line.substr(0, i);
				}
			}
		}
		instruction instr;
		line_number += 1;
		instr.line_number = line_number;
		if (line.find(":") != string::npos) {
			instr.hasLabel = true;
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == ':') {
					string label_name = line;
					label_name = label_name.substr(0, i);
					int length = line.length();
					line = line.substr(i + 1, length - i);
					instr.label = label_name;
					instr.opcode = "nop";
					instructions.push_back(instr);
					label2line[instr.label] = instr.line_number;
				}
			}
		} else {
			instr.hasLabel = false;
			int i = 0;
			while (isalpha(line[i]) && i < line.length()) {
				i++;
			}
			i++;
			for (int j = i; j < line.length(); j++) {
				string opcode = "";
				opcode += line[j++];
				while ((isalnum(line[j]) || line[j] == '_') && j < line.length()) {			
					opcode += line[j];
					j++;
				}
				instr.opcode = opcode;
				if (opcode == "halt") {
					instructions.push_back(instr);
					return;
				}
				else if (opcode == "output" || opcode == "coutput" || opcode == "write" || opcode == "cwrite") {
					while (line[j] == ' ' && j < line.length()) {
						j++;
					}
					string tmp = "";
					tmp += line[j++];
					while (line[j] != ' ' && j < line.length()) {
						tmp += line[j];
						j++;
					}
					instr.leftOperands.push_back(tmp);
					instructions.push_back(instr);
					break;
				}
				else if (opcode == "br") {
					while (line[j] != '-' && j < line.length()) {
						j++;
					}
					j++;
					j++;
					while (line[j] == ' ' && j < line.length()) {
						j++;
					}
					string tmp = "";
					while (isalnum(line[j]) && j < line.length()) {
						tmp += line[j];
						j++;
					}
					instr.rightOperands.push_back(tmp);
					instructions.push_back(instr);
					break;
				}
				else if (opcode == "cbr") {
					while (line[j] == ' ' && j < line.length()) {
						j++;
					}
					string left = "";
					left += line[j++];
					while (isalnum(line[j]) && j < line.length()) {
						left += line[j];
						j++;
					}
					instr.leftOperands.push_back(left);
					while (line[j] != '-' && j < line.length()) {
						j++;
					}
					j++;
					j++;
					while (line[j] == ' ' && j < line.length()) {
						j++;
					}
					string right1 = "";
					right1 += line[j++];
					while (line[j] != ',' && j < line.length()) {
						right1 += line[j];
						j++;
					}
					j++;
					while (line[j] == ' ' && j < line.length()) {
						j++;
					}
					string right2 = "";
					right2 += line[j++];
					while (isalnum(line[j]) && j < line.length()) {
						right2 += line[j];
						j++;
					}
					instr.rightOperands.push_back(right1);
					instr.rightOperands.push_back(right2);
					instructions.push_back(instr);
					break;
				}
				else if (opcode == "read" || opcode == "cread") {
					while (line[j] == ' ' && j < line.length()) {
						j++;
					}
					j++;
					j++;
					while (line[j] == ' ' && j < line.length()) {
						j++;
					}
					string tmp = "";
					while (isalnum(line[j]) && j < line.length()) {
						tmp += line[j];
						j++;
					}
					instr.rightOperands.push_back(tmp);
					instructions.push_back(instr);
					break;
				}
				else if (opcode == "not" || opcode == "loadI" || opcode == "load"
						|| opcode == "cload" || opcode == "store" || opcode == "cstore" || opcode == "i2i"
						|| opcode == "c2c" || opcode == "i2c" || opcode == "c2i") 
				{
					while (line[j] == ' ' && j < line.length()) {
						j++;
					}
					string left = "";
					left += line[j++];
					while (isalnum(line[j]) && j < line.length()) {
						left += line[j];
						j++;
					}
					while (line[j] != '=' && j < line.length()) {
						j++;
					}
					j++;
					j++;
					while (line[j] == ' ' && j < line.length()) {
						j++;
					}
					string right = "";
					right += line[j++];
					while (isalnum(line[j]) && j < line.length()) {
						right += line[j];
						j++;
					}
					instr.leftOperands.push_back(left);
					instr.rightOperands.push_back(right);
					instructions.push_back(instr);
					break;
				}
				else if (opcode == "storeAI" || opcode == "storeAO" || opcode == "cstoreAI" || opcode == "cstoreAO") {
					while (line[j] == ' ' && j < line.length()) {
						j++;
					}
					string left = "";
					left += line[j++];
					while (isalnum(line[j]) && j < line.length()) {
						left += line[j];
						j++;
					}
					while (line[j] != '=' && j < line.length()) {
						j++;
					}
					j++;
					j++;
					while (line[j] == ' ' && j < line.length()) {
						j++;
					}
					string right1 = "";
					right1 += line[j++];
					while (line[j] != ',' && j < line.length()) {
						right1 += line[j];
						j++;
					}
					j++;
					while (line[j] == ' ' && j < line.length()) {
						j++;
					}
					string right2 = "";
					right2 += line[j++];
					while (isalnum(line[j]) && j < line.length()) {
						right2 += line[j];
						j++;
					}
					instr.leftOperands.push_back(left);
					instr.rightOperands.push_back(right1);
					instr.rightOperands.push_back(right2);
					instructions.push_back(instr);
					break;
				}
				else {
					while (line[j] == ' ' && j < line.length()) {
						j++;
					}
					string left1 = "";
					left1 += line[j++];
					while (line[j] != ',' && j < line.length()) {
						left1 += line[j];
						j++;
					}
					j++;
					while (line[j] == ' ' && j < line.length()) {
						j++;
					}
					string left2 = "";
					left2 += line[j++];
					while (isalnum(line[j]) && j < line.length()) {
						left2 += line[j];
						j++;
					}
					while (line[j] != '=' && j < line.length()) {
						j++;
					}
					j++;
					j++;
					while (line[j] == ' ' && j < line.length()) {
						j++;
					}
					string right = "";
					right += line[j++];
					while (isalnum(line[j]) && j < line.length()) {
						right += line[j];
						j++;
					}
					instr.leftOperands.push_back(left1);
					instr.leftOperands.push_back(left2);
					instr.rightOperands.push_back(right);
					instructions.push_back(instr);
					break;
				}
			}
		}
		
	}
}

void OutputParseResults(vector<instruction> instructions) {
	for (auto x : instructions) {
		ofstream outfile;
		outfile.open ("output.i", ios::app);
		if (x.opcode == "halt") {
			outfile << x.opcode << x.line_number << endl;
		}
		else if (x.opcode == "nop") {
			outfile << x.label << ": " << x.opcode << endl; 
		}
		else if (x.opcode == "output" || x.opcode == "coutput" || x.opcode == "write" || x.opcode == "cwrite") {
			outfile << x.opcode << " " << x.leftOperands[0] << endl;
		}
		else if (x.opcode == "read" || x.opcode == "cread") {
			outfile << x.opcode << " => " << x.rightOperands[0] << endl;
		}
		else if (x.opcode == "br") {
			outfile << x.opcode << " -> " << x.rightOperands[0] << endl; 
		}
		else if (x.opcode == "cbr") {
			outfile << x.opcode << " " << x.leftOperands[0] << " -> " << x.rightOperands[0] << ", " << x.rightOperands[1] << endl;
		}
		else if (x.opcode == "not" || x.opcode == "loadI" || x.opcode == "load"
				|| x.opcode == "cload" || x.opcode == "store" || x.opcode == "cstore" || x.opcode == "i2i"
				|| x.opcode == "c2c" || x.opcode == "i2c" || x.opcode == "c2i") 
		{
			outfile << x.opcode << " " << x.leftOperands[0] << " => " << x.rightOperands[0] << endl;
		}
		else if (x.opcode == "storeAI" || x.opcode == "storeAO" || x.opcode == "cstoreAI" || x.opcode == "cstoreAO") {
			outfile << x.opcode << " " << x.leftOperands[0] << " => " << x.rightOperands[0] << ", " << x.rightOperands[1] << endl;
		}
		else {
			outfile << x.opcode << " " << x.leftOperands[0] << ", " << x.leftOperands[1] << " => " << x.rightOperands[0] << endl;
		}
		outfile.close();
	}	
}

void buildCFG(vector<int> &leader, vector<int> &last, vector<instruction> instructions) {
	leader.push_back(1);
	unordered_set<int> leaders_set;
	leaders_set.insert(1);
	for (auto x : instructions) {
		if (x.opcode == "br") {
			if (leaders_set.find(label2line[x.rightOperands[0]]) == leaders_set.end()) {
				leader.push_back(label2line[x.rightOperands[0]]);
				leaders_set.insert(label2line[x.rightOperands[0]]);
			}
		}
		else if (x.opcode == "cbr") {
			if (leaders_set.find(label2line[x.rightOperands[0]]) == leaders_set.end()) {
				leader.push_back(label2line[x.rightOperands[0]]);
				leaders_set.insert(label2line[x.rightOperands[0]]);
			}
			if (leaders_set.find(label2line[x.rightOperands[1]]) == leaders_set.end()) {
				leader.push_back(label2line[x.rightOperands[1]]);
				leaders_set.insert(label2line[x.rightOperands[1]]);
			}
		}
	}
	instruction instr = instructions.back();
	int total_line_number = instr.line_number;
	for (int i = 0; i < leader.size(); i++) {
		int tmp = leader[i];
		while (tmp <= total_line_number && leaders_set.find(tmp + 1) == leaders_set.end()) {
			tmp++;
		}
		last.push_back(tmp);
	}
}

int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "missing input file" << endl;
		return -1;
	}
	
	string filename = argv[1];
	vector<instruction> instructions;
	ParseInstructions(filename, instructions);
	
	OutputParseResults(instructions);
	
	vector<int> leader;
	vector<int> last;
	buildCFG(leader, last, instructions);
	
	for (int i = 0; i < leader.size(); i++) {
		cout << leader[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < last.size(); i++) {
		cout << last[i] << " ";
	}
	cout << endl;
	
	return 0;
}