#include <iostream>
#include <string>

using namespace std;

int main()
{
    string message(""), sousChaineF(""), messageChiffre("");
    char decalage('-');
    string cles("cryptographie");


    cout << "Entrez le message a chiffrer : ";
    cin >> message;

    //Chiffrer le message

    sousChaineF = message.substr(message.size()/2);
    message = sousChaineF + message.substr(0,message.size()/2);

    for (int i(0) ; i < message.size() ; i++)
    {
        messageChiffre += (message[i]^cles[i%cles.size()]) +decalage;
    }

    cout << messageChiffre << endl;

    //Dechiffrer le message

    message = "";

    for (int i(0) ; i < messageChiffre.size() ; i++)
    {
        message += ((messageChiffre[i] - decalage)^cles[i%cles.size()]);
    }

    if (message.size()%2 != 0)
    {
        sousChaineF += +1 ;
    }

    sousChaineF = message.substr(message.size()/2);
    message = sousChaineF + message.substr(0,message.size()/2);


    cout << message;




    return 0;
}
