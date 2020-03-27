#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    float similarity = 0;
    int collisions = 0;

    string adn1, adn2;
    string input1 = "", input2 = "";

    //load first file

    ifstream dataFile("seq1.txt");

    if (dataFile)
        while (getline(dataFile, input1))
            adn1 += input1;

    //load second file

    ifstream dataFile1("seq2.txt");

    if (dataFile1)
        while (getline(dataFile1, input2))
            adn2 += input2;

    // do comparison

    if( adn1=="" or adn2=="" ){

        cout << "One or more files were not loaded, please check the file/s location or content. The files must be named seq1 and seq2." << endl;
        here:
        cout << "IMPORTANT: The only content permitted in the sequences files is strictly the sequences themselves, no header. " << endl;
        return 0;
    }

    for( int i=0 ; i < min(adn1.size() , adn2.size()); ++i){
        if( i < 200 && ((adn1[i]!= 'A' && adn1[i]!= 'G' && adn1[i]!= 'C' && adn1[i]!= 'T' && adn1[i]!= 'U') || (adn2[i]!= 'A' && adn2[i]!= 'G' && adn2[i]!= 'C' && adn2[i]!= 'T' && adn2[i]!= 'U')) ){
            goto here;
        }
        if(adn1[i] == adn2[i]){
            collisions += 1;
        }
    }

    //final analysis


    similarity =  collisions / float( min(adn1.size() , adn2.size() ) );

    cout << "The length of the first sequence is : " << adn1.size() << " and the length of the second sequence is : " << adn2.size() << endl << endl;

    cout << similarity * 100 << "% of similarity between the two sequences" << endl <<endl;

    cout << "Dev note: The similarity is calculated by  (collisions / length of the shortest sequence)." << endl;
    cout << "The sequences are analysed from the beginning until the shortest sequence is finished." << endl;

    return 0;
}
