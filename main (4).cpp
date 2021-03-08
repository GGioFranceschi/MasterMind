/* 
** MasterMind
** Giorgia Franceschi 
** 5/03/2021
*/

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class Mastermind{
    private:
    void init(){
        srand (time(NULL));
        for (int i=0; i<5; i++){
            mappa [i]= (rand () % 10) +1;
            for (int j=0; j<i; j++){
                if (mappa [i]== mappa[j]){
                    i--;
                    break;
                }
            }
        }
    }
    int mappa[5];
    int test[5];
    public:
    Mastermind(){
        init();
    }
    void stampa(){
        for(int i=0; i<5; i++){
            cout<<mappa[i]<<"\t";
        }
        cout<<endl;
    }
    void play(){
        cout<<"Inserisci 5 numeri interi"<<endl;
        for (int i=0; i<5; i++){
            cin>>test[i];
            for (int j=0; j<i; j++){
                if (test [i]== test[j]){
                    cout <<"ERRORE: NUMERO RIPETUTO" <<endl;
                    cout <<"inserire un numero diverso dal/i precedenti: ";
                    cin>>test [i];
                }
            }
        }
        for (int i=0; i<5; i++){
            cout<<test[i]<<"\t";
        }
    }
    bool check(){
        int strike=0, ball=0;
        for(int a=0; a<5; a++){
            for(int b=0; b<5; b++){
                if(test[a]==mappa[b]){
                    if(a==b){
                        strike++;
                    } else {
                        ball++;
                    }
                }
                
            }
        }
        cout<<endl<<"Strike: "<<strike<<endl<<"Ball: "<<ball<<endl;
        return strike==5;
    }
};
int main(){
    srand(time(NULL));
    cout<<"Programma MasterMind avviato!"<<endl;

    Mastermind m;
    m.stampa();
    do{
        m.play();
    } while(!m.check());
    

    return 0;
}



