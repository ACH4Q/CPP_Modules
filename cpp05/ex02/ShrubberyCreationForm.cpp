#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target): AForm("Shrubbery Form",145,137) , target(_target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::executing()
{
    std::ofstream outfile((this->target + "_shrubbery").c_str());
    if (!outfile.is_open())
        std::cerr << "cannot open file" << std::endl;
        outfile << "                                  ,--,        ,--,                 " << std::endl;
    outfile << "   ,---,         ,----..        ,--.'|      ,--.'|    ,----..      " << std::endl;
    outfile << "  '  .' \\       /   /   \\    ,--,  | :   ,--,  | :   /   /   \\     " << std::endl;
    outfile << " /  ;    '.    |   :     :,---.'|  : ',---.'|  : '  /   .     :    " << std::endl;
    outfile << ":  :       \\   .   |  ;. /|   | : _' |;   : |  | ; .   /   ;.  \\   " << std::endl;
    outfile << ":  |   /\\   \\  .   ; /--` :   : |.'  ||   | : _' |.   ;   /  ` ;   " << std::endl;
    outfile << "|  :  ' ;.   : ;   | ;    |   ' '  ; ::   : |.'  |;   |  ; \\ ; |   " << std::endl;
    outfile << "|  |  ;/  \\   \\|   : |    '   |  .'. ||   ' '  ; :|   :  | ; | '   " << std::endl;
    outfile << "'  :  | \\  \\ ,'.   | '___ |   | :  | '\\   \\  .'. |.   |  ' ' ' :   " << std::endl;
    outfile << "|  |  '  '--'  '   ; : .'|'   : |  : ; `---`:  | ''   ;  \\; /  |   " << std::endl;
    outfile << "|  :  :        '   | '/  :|   | '  ,/       '  ; | \\   \\  ',  . \\  " << std::endl;
    outfile << "|  | ,'        |   :    / ;   : ;--'        |  : ;  ;   :      ; | " << std::endl;
    outfile << "`--''           \\   \\ .'  |   ,/            '  ,/    \\   \\ .'`--\"  " << std::endl;
    outfile << "                 `---`    '---'             '--'      `---` " << std::endl;
    outfile.close();
}

