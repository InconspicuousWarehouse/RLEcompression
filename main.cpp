#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

string O_file_Buffer(string text, string& filename);
string Text_Compression(string output, string text, int z);
fstream file;

int main()
{
    string text = "";
    string output = "";
    float compression;
    string filename, filename1;
    char choice;

    cout << "RLE (Run-Length Encoding) || RLE - technique that compresses consecutive occurrences of the same letter in a sequence."<< endl
         <<"BBssssscgggflpaaaaaa -> BB0ss3cgg1flpaa4 " << endl;

    while (true)
    {
        cout << "Type in 1 to run RLE program, or Q to quit: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == '1')
        {
            text = O_file_Buffer(text, filename);
            if (text == "-1")
            {
                continue;
            }
            cout <<  "////////////////////////////////////////////////////////////////////////////////"<< '\n'
                 <<"File content: " << text << endl;

            int z = text.length();
            cout  << "////////////////////////////////////////////////////////////////////////////////"<< '\n'
                  << "This is length of text: " << z << endl;

            output = Text_Compression(text, output, z);
            cout << " This is compressed text: " << output << endl;

            int o = output.length();
            compression = (float(o) / float(z));
            cout << " Compression ratio=(output length / primary length): " << compression << endl;

            int co = output.length();
            cout << " This is length of compressed text: " << co << endl;

            cout << '\n' << "Click 'Q' to quit the program or '1' to save the compressed text in a text file"
                            " (which will be created automatically in the path you have specified) with its name followed by '_compressed'." << endl;
            string save;
            getline(cin, save);
            if (save == "1")
            {
                string outputFilename = filename.substr(0, filename.find_last_of('.')) + "_compressed.txt";
                file.open(outputFilename, ios::out);
                if (file.is_open())
                {
                    file << output;
                    file.close();
                    cout  << "////////////////////////////////////////////////////////////////////////////////"<< '\n'
                          << "Compressed text has been successfully saved in your file!" << '\n' << endl;

                    cout << "Number of characters in compressed text: " << o << endl;
                }
                else
                {
                    cout << "Error: Unable to open the file for writing." << endl;
                }
            }
            else if (save == "Q" || save == "q")
            {
                cout << "Closing the program..." << endl;
                return 0;
            }
            else
            {
                cout << "It wasn't an option..." << endl;
            }
        }
        else if (choice == 'Q' || choice == 'q')
        {
            cout << "Closing the program..." << endl;
            return 0;
        }
        else
        {
            cout << "It wasn't an option..." << endl;
        }
    }
    return 0;
}

string O_file_Buffer(string text, string& filename)
{
    while (true)
    {
        cout << "Please enter the absolute path of the text file you wish to compress:" << endl
             << "or click Q or q to quit the program," << endl << "-> ";
        getline(cin, filename);

        if (filename == "q" || filename == "Q")
        {
            cout << "Closing the program..." << endl;
            exit(0);
        }

        file.open(filename);
        if (file.is_open())
        {
            break;
        }
        else
        {
            cout << "File doesn't exist. Please try again: ";
        }
    }

    stringstream buffer;
    buffer << file.rdbuf();
    text += buffer.str();
    file.close();
    return text;
}

string Text_Compression(string text, string output, int z)
{
    int i = 0, count1;
    for (i = 0; i < z; i++)
    {
        count1 = -1;
        while (text[i] == text[i + 1] && i < (z - 1))
        {
            count1++;
            i++;
        }

        if (text[i] == text[i - 1])
        {
            output += text[i];
            output += text[i];
            output += to_string(count1);
        }
        else
        {
            output += text[i];
        }
    }
    return output;
}
