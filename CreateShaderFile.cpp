#include <iostream>
#include <fstream>
#include <string>

void create_shader_bin(const std::string& vertex_shader_path, const std::string& fragment_shader_path, const std::string& output_path) {
    std::ifstream vertexFile(vertex_shader_path);
    std::ifstream fragmentFile(fragment_shader_path);
    std::ofstream outputFile(output_path, std::ios::binary);

    if (!vertexFile.is_open() || !fragmentFile.is_open() || !outputFile.is_open())
    {
        std::cerr << "Error opening files!" << std::endl;
        return;
    }

    std::string line;
    outputFile << "//VERTEX\n";
    while (std::getline(vertexFile, line))
    {
        outputFile << line << "\n";
    }

    outputFile << "\n//FRAGMENT\n";
    while (std::getline(fragmentFile, line))
    {
        outputFile << line << "\n";
    }

    vertexFile.close();
    fragmentFile.close();
    outputFile.close();
}

int main()
{
    create_shader_bin("Shaders/Shader.vert", "Shaders/Shader.frag", "shaders.bin");
    std::cout << "Shaders combined successfully!" << std::endl;
    return 0;
}