#

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

namespace DEBUG {
    bool arquivos_iguais(string& arq1_str,
                         string& arq2_str){
        
        ifstream arq1(arq1_str), arq2(arq2_str);
        string linha1, linha2;

        if(!arq1 || !arq2) return false;

        while (true) {
            if (arq1.eof() || arq2.eof()) {
                if (arq1.eof() && arq2.eof())
                    return true;
                else
                    return false;
            }

            getline (arq1, linha1);
            getline (arq2, linha2);
            
            if (linha1 != linha2)
                return false;
        }
        
        cout << "ESTA LINHA DE CODIGO NAO DEVERIA SER PROCESSADA!" << endl;
        return false;
    }
}
