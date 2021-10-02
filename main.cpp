#include "lexer.h"
#include "parser.h"

int main (int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "please provide input files";
        return 1;
    }
    std::ifstream in(argv[1]);
    if (!in) {
        std::cerr << "unable to open " << argv[1] << " for input";
        return 2;
    } else {
        string filename = argv[1];
        lexer mylexer(filename);  
        mylexer.tokenize();
        Parser myParser;
        bool trueorfalse = myParser.DatalogProgram(mylexer.GetList());
        if (trueorfalse == false) {
            myParser.ToString();
        }
    }
    return 0;
}