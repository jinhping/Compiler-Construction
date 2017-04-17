#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "code.h"
#include <cctype>
#include <unordered_map>
#include <math.h>
#include <algorithm>

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
			outfile << x.opcode << endl;
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
	//int total_line_number = instr.line_number;
	int total_line_number = instructions.size();
	for (int i = 0; i < leader.size(); i++) {
		int tmp = leader[i];
		while (tmp <= total_line_number && leaders_set.find(tmp + 1) == leaders_set.end()) {
			tmp++;
		}
		last.push_back(tmp);
	}
}

bool IsPowerOfTwo(int x)
{
    return (x & (x - 1)) == 0;
}

void localValueNumbering(vector<int> leader, vector<int> last, vector<instruction> &instructions) {
	int basic_block_number = leader.size();
	for (int i = 0; i < basic_block_number; i++) {
		int begin = leader[i] - 1;
		int end = last[i] - 1;
		
		unordered_map <string, int> expr2VN;
		unordered_map <string, int> VN;
		unordered_map <int, string> name;
		int new_value_number = 0;
		
		for (int j = begin; j <= end; j++) {
			if (instructions[j].opcode == "nop" || instructions[j].opcode == "not" || instructions[j].opcode == "store"
				|| instructions[j].opcode == "storeAI" || instructions[j].opcode == "storeAO" || instructions[j].opcode == "cstore"
				|| instructions[j].opcode == "cstoreAI" || instructions[j].opcode == "cstoreAO"  || instructions[j].opcode == "i2i"
				|| instructions[j].opcode == "c2c" || instructions[j].opcode == "i2c" || instructions[j].opcode == "c2i"
				|| instructions[j].opcode == "br" || instructions[j].opcode == "cbr" || instructions[j].opcode == "halt" 
				|| instructions[j].opcode == "read" || instructions[j].opcode ==  "cread" || instructions[j].opcode == "output"
				|| instructions[j].opcode == "coutput" || instructions[j].opcode == "write" || instructions[j].opcode == "cwrite"
				|| instructions[j].opcode == "loadI" || instructions[j].opcode == "load" || instructions[j].opcode ==  "cload") {
				if (instructions[j].opcode == "halt") {
					break;
				}
				continue;
			}
			else {
				if (instructions[j].opcode == "multI") {		
					if (IsPowerOfTwo(stoi(instructions[j].leftOperands[1]))) {
						double tmp_d = sqrt(stoi(instructions[j].leftOperands[1]));
						int tmp = tmp_d;
						instruction instr;
						instr.opcode = "lshiftI";
						instr.leftOperands.push_back(instructions[j].leftOperands[0]);
						instr.leftOperands.push_back(to_string(tmp));
						instr.rightOperands.push_back(instructions[j].rightOperands[0]);
						instructions[j] = instr;
					}
				} 
			
				if (VN.find(instructions[j].leftOperands[0]) == VN.end()) {
					VN[instructions[j].leftOperands[0]] = new_value_number;
					new_value_number += 1;
				}
				if (VN.find(instructions[j].leftOperands[1]) == VN.end()) {
					VN[instructions[j].leftOperands[1]] = new_value_number;
					new_value_number += 1;
				}

				string expr = to_string(VN[instructions[j].leftOperands[0]]) + instructions[j].opcode + to_string(VN[instructions[j].leftOperands[1]]);
				if (expr2VN.find(expr) != expr2VN.end()) {
					if (VN[name[expr2VN[expr]]] == expr2VN[expr]) {
						instruction instr;
						instr.opcode = "i2i";
						instr.leftOperands.push_back(name[expr2VN[expr]]);
						instr.rightOperands.push_back(instructions[j].rightOperands[0]);
						instructions[j] = instr;
					}
					VN[instructions[j].rightOperands[0]] = expr2VN[expr];
				}
				else {
					VN[instructions[j].rightOperands[0]] = new_value_number;
					expr2VN[expr] = new_value_number;
					name[new_value_number] = instructions[j].rightOperands[0];
					new_value_number++;
				}
			}
		}
		
	}
}

void getNewValues(vector<instruction> instructions, int &new_register, int &new_label) {
	for (auto x : instructions) {
		if (x.label != "") {
			int length = x.label.length();
			string tmp_label = x.label.substr(1, length - 1);
			int tmp_label_value = stoi(tmp_label);
			if (tmp_label_value > new_label) {
				new_label = tmp_label_value;
			}
		}
		if (x.leftOperands.size() != 0) {
			for (auto y : x.leftOperands) {
				if (y[0] != 'r') {
					continue;
				}
				int length = y.length();
				string tmp_register = y.substr(1, length -  1);
				int tmp_register_value = stoi(tmp_register);
				if (tmp_register_value > new_register) {
					new_register = tmp_register_value;
				}
			}
		}
		if (x.rightOperands.size() != 0) {
			for (auto z : x.rightOperands) {
				if (z[0] != 'r') {
					continue;
				}
				int length = z.length();
				string tmp_register = z.substr(1, length -  1);
				int tmp_register_value = stoi(tmp_register);
				if (tmp_register_value > new_register) {
					new_register = tmp_register_value;
				}
			}
		}
	}
}


void loopUnrolling(vector<int> leader, vector<int> last,vector<instruction> &instructions, 
				int new_register, int new_label) 
{
//	cout << "before" << endl;
	vector<instruction> insert_instructions;

	int basic_block_number = leader.size();
	for (int i = 0; i < basic_block_number; i++) {
		int begin = leader[i] - 1;
		int end = last[i] - 1;
		
	//	cout << "begin: " << begin << endl;
	//	cout << "end: " << end << endl;
		
	//	cout << instructions[begin].opcode << endl;
	
		
		if (instructions[end - 1].opcode == "halt") {
			for (int k = begin; k <= end - 1; k++) {
				insert_instructions.push_back(instructions[k]);
			}
			instructions.swap(insert_instructions);
			continue;
		}
		if (instructions[begin].label != "" && instructions[end].opcode == "cbr") {
			if (instructions[begin].label == instructions[end].rightOperands[0] && instructions[end - 2].opcode == "addI") {
				// do loop unrolling by 4
				
	//			cout << "before assign new" << endl;
				
				instruction instr1;
				instr1.opcode = "nop";
				instr1.label = instructions[begin].label;
				insert_instructions.push_back(instr1);
				
				instruction instr2;
				instr2.opcode = "rshiftI";
				instr2.leftOperands.push_back(instructions[end - 1].leftOperands[1]);
				instr2.leftOperands.push_back("2");
				string new_r = "r" + to_string(new_register + 1);
				new_register += 1;
				instr2.rightOperands.push_back(new_r);
				insert_instructions.push_back(instr2);
				
				instruction instr3;
				instr3.opcode = "lshiftI";
				instr3.leftOperands.push_back(new_r);
				instr3.leftOperands.push_back("2");
				instr3.rightOperands.push_back(new_r);
				insert_instructions.push_back(instr3);
				
				instruction instr4;
				instr4.opcode = "cbr";
				instr4.leftOperands.push_back(new_r);
				string new_label_1 = "L" + to_string(new_label + 1);
				new_label = new_label + 1;
				instr4.rightOperands.push_back(new_label_1);
				string new_label_2 = "L" + to_string(new_label + 1);
				new_label = new_label + 1;
				instr4.rightOperands.push_back(new_label_2);
				insert_instructions.push_back(instr4);
				
				instruction instr5;
				instr5.opcode = "nop";
				instr5.label = new_label_1;
				insert_instructions.push_back(instr5);
				
				for (int b = 0; b < 4; b++) {
					for (int a = begin + 1; a <= end - 2; a++) {
						insert_instructions.push_back(instructions[a]);
					}
				}
				
				instruction instr6;
				instr6.opcode = instructions[end - 1].opcode;
				instr6.leftOperands.push_back(instructions[end - 1].leftOperands[0]);
				instr6.leftOperands.push_back(new_r);
				instr6.rightOperands.push_back(instructions[end].leftOperands[0]);
				insert_instructions.push_back(instr6);
				
				instruction instr7;
				instr7.opcode = "cbr";
				instr7.leftOperands.push_back(instructions[end].leftOperands[0]);
				instr7.rightOperands.push_back(new_label_1);
				instr7.rightOperands.push_back(new_label_2);
				insert_instructions.push_back(instr7);

				
				//starting with L12: 
				instruction instr8;
				instr8.opcode = "nop";
				instr8.label = new_label_2;
				insert_instructions.push_back(instr8);

				insert_instructions.push_back(instructions[end - 1]);
				
				instruction instr9;
				instr9.opcode = "cbr";
				instr9.leftOperands.push_back(instructions[end].leftOperands[0]);
				string new_label_3 = "L" + to_string(new_label + 1);
				new_label = new_label + 1;
				instr9.rightOperands.push_back(new_label_3);
				instr9.rightOperands.push_back(instructions[end].rightOperands[1]);
				insert_instructions.push_back(instr9);
				
				//starting with L13:
				instruction instr10;
				instr10.opcode = "nop";
				instr10.label = new_label_3;
				insert_instructions.push_back(instr10);
				
				for (int c = begin + 1; c <= end - 2; c++) {
					insert_instructions.push_back(instructions[c]);
				}
				
				insert_instructions.push_back(instructions[end - 1]);
				insert_instructions.push_back(instr9);
				
	//			cout << "after assign new" << endl;

			} 
			else {
	//			cout << "here" << endl;
				for (int k = begin; k <= end; k++) {
					insert_instructions.push_back(instructions[k]);
				}
				continue;
			}
		}
		else {
	//		cout << "there" << endl;
			for (int k = begin; k <= end; k++) {
				insert_instructions.push_back(instructions[k]);
			}
			continue;
		}

	}
//	cout << "after" << endl;
}

void updateLineNumber(vector<instruction> &instructions, unordered_map<string, int> &label2line) {
	int line_number = 1;
	for (auto x : instructions) {
		x.line_number = line_number;
		line_number ++;
		if (x.label != "") {
			label2line[x.label] = x.line_number;
		}
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
	
		

	
	

	
	vector<int> leader2;
	vector<int> last2;
	
	buildCFG(leader2, last2, instructions);
	
	int new_register = -1;
	int new_label = -1;
	
	getNewValues(instructions, new_register, new_label);
	
	sort(leader2.begin(), leader2.end());
	sort(last2.begin(), last2.end());

	for (auto x : leader2) {
		cout << x << " ";
	}
	cout << endl;
	for (auto x : last2) {
		cout << x << " ";
	}
	cout << endl;
	
	loopUnrolling(leader2, last2, instructions, new_register, new_label);
	
	
	updateLineNumber(instructions, label2line);

	
	vector<int> leader;
	vector<int> last;
	buildCFG(leader, last, instructions);
	
/* 	for (auto x : leader) {
		cout << x << " ";
	}
	cout << endl;
	for (auto x : last) {
		cout << x << " ";
	}
	cout << endl; */
	
	
	localValueNumbering(leader, last, instructions);
	
	OutputParseResults(instructions);

	
	return 0;
}