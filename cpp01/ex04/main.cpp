#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>


void replace_string(std::string &str, const std::string s1,const std::string s2)
{
	std::string::size_type pos = 0;
	while ((pos = str.find(s1, pos)) != std::string::npos)
	{
		str.erase(pos, s1.length());
		str.insert(pos, s2);
		pos += s2.length();
	}
}

int main(int ac , char **av)
{
	if(ac != 4)
	{
		std::cerr << "Usage " << av[0] << " Filename \"string\" \"toreplacestring\"" << std::endl;
		return (1);
	}

	if (std::string(av[2]).empty() || std::string(av[3]).empty())
	{
        std::cerr << "Error: Search string cannot be empty." << std::endl;
        return 1;
    }

	std::ifstream filein;
	std::ofstream fileout;
	std::string str = av[1];
	filein.open((char *)str.c_str());
	if(!filein.is_open())
	{
		std::cerr << "Error: file not found" << std::endl;
		return (1);
	}
	filein.seekg(0, filein.end);
	int size = filein.tellg();
	if (size == 0)
	{
        std::cerr << "The input file is empty." << std::endl;
        filein.close();
        return 0;
    }
	filein.seekg(0, filein.beg);
	fileout.open(str.append(".replace").c_str());
	if(!fileout.is_open())
	{
		std::cerr << "Error: file not found" << std::endl;
		return (1);
	}
	std::string buff;
	buff.resize(size);
	filein.read((char *)buff.c_str() , size);
	std::string s1 = av[2];
	std::string s2 = av[3];
	replace_string(buff, s1 , s2);
	fileout.write(buff.c_str(), buff.length());
	fileout.close();
	filein.close();
}
