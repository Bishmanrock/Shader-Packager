#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

bool verifyShaderFile(const std::string& filePath, const std::vector<std::vector<std::string>>& expectedShaders) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filePath << " for verification.\n";
        return false;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string fileContents = buffer.str();

    // Reconstruct the expected contents from the vector of shader strings
    std::string expectedConcatenated;
    for (const auto& shaderGroup : expectedShaders) {
        for (const auto& shader : shaderGroup) {
            expectedConcatenated += shader; // Adjust based on actual file format, e.g., adding delimiters if necessary
        }
    }

    return fileContents == expectedConcatenated;
}

void create_shader_bin(const std::string& vertex_shader_path, const std::string& fragment_shader_path, const std::string& editor_shader_path, const std::string& output_path)
{
    std::ifstream vertexFile(vertex_shader_path);
    std::ifstream fragmentFile(fragment_shader_path);
    std::ifstream editorFile(editor_shader_path); // Open the editor shader file
    std::ofstream outputFile(output_path, std::ios::binary);

    if (!vertexFile.is_open() || !fragmentFile.is_open() || !editorFile.is_open() || !outputFile.is_open())
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

    outputFile << "\n//EDITOR\n"; // Add the EDITOR section
    while (std::getline(editorFile, line))
    {
        outputFile << line << "\n";
    }

    vertexFile.close();
    fragmentFile.close();
    editorFile.close(); // Close the editor shader file
    outputFile.close();

    std::vector<std::vector<std::string>> shaders =
    {
    std::vector<std::string>{vertexFile}, // Vertex shader(s)
    std::vector<std::string>{fragmentFile}, // Fragment shader(s)
    std::vector<std::string>{editorFile} // Editor shader(s)
    };

    bool isCorrect = verifyShaderFile("shaders.bin", shaders);
    if (isCorrect) {
    std::cout << "Verification successful: The .bin file contents match the expected contents.\n";
    } else {
    std::cerr << "Verification failed: The .bin file contents do not match the expected contents.\n";
    }
}

int main()
{
    create_shader_bin("Shaders/Shader.vert", "Shaders/Shader.frag", "Shaders/Editor.frag", "shaders.bin");
    std::cout << "Shaders combined successfully!" << std::endl;
    return 0;
}
