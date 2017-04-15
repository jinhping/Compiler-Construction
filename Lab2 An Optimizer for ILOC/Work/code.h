#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<string> opcodes_set( {
"nop", "add", "addl", "sub", "subl", "mult", "multl", "div", "divl", "lshift", "lshiftl", "rshift", "rshiftl",
"and", "andl", "or", "orl", "not", "loadl", "load", "loadAI", "loadAO", "cload", "cloadAI", "cloadAO", 
"store", "storeAI", "storeAO", "cstore", "cstoreAI", "cstoreAO", "i2i", "c2c", "i2c", "c2i", "br", "cbr",
"cmp_LT", "cmp_LE", "cmp_GT", "cmp_GE", "cmp_EQ", "cmp_NE", "halt", "read", "cread", "output", "coutput",
"write", "cwrite"
} );

bool isOpcode(char * token) {
	string s = token;
	if (opcodes_set.find(s) != opcodes_set.end()) {
		return true;
	} else {
		return false;
	}
}

class instruction {
public:
	string label = "";
	string opcode = "";
	
	vector<string> leftOperands;
	vector<string> rightOperands;
	
	bool hasLabel = false;
	
	int line_number = 0;
};

