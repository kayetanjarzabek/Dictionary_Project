# Dictionary Project

This project provides a simple command-line interface to look up definitions, synonyms, antonyms, and examples of usage for words using the Free Dictionary API found at [DictionaryAPI](https://dictionaryapi.dev/).

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/kayetanjarzabek/Dictionary_Project.git
    ```

2. Compile the source code:

    ```bash
    g++ -o dictionary main.cpp -lcurl
    ```

3. Run the executable:

    ```bash
    ./dictionary
    ```

## Usage

When you run the program, you will be presented with a menu:

1. **Define a Word**: Look up definitions, synonyms, antonyms, and examples of usage for a word.
2. **Save All to a Text File**: Save all the words and their definitions to a text file.
3. **Additional Information**: View additional information about the project and its dependencies.
4. **Quit**: Exit the program.

## Dependencies

- [nlohmann/json](https://github.com/nlohmann/json): A JSON library for Modern C++
- [curlpp](https://github.com/jpbarrette/curlpp): C++ wrapper for libcURL

## Credits

This project was created by [Kayetan](https://github.com/kayetanjarzabek).

## License


## Disclaimer

This project is for educational purposes only and is not intended for any commercial use. The data provided by the Free Dictionary API may be subject to terms and conditions specified by the API provider.
