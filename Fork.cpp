
#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <cstdlib>
#include <pthread.h>

using namespace std;


string doc = "The primroses were over. Toward the edge of the wood, where the ground became open and sloped down to an old fence and a brambly ditch beyond, only a few fading patches of pale yellow still showed among the dog's mercury and oak-tree roots. On the other side of the fence, the upper part of the field was full of rabbit holes. In places the grass was gone altogether and everywhere there were clusters of dry droppings, through which nothing but the ragwort would grow. A hundred yards away, at the bottom of the slope, ran the brook, no more than three feet wide, half choked with king cups, watercress and blue brook lime. The cart track crossed by a brick culvert and climbed the opposite slope to a five- barred gate in the thorn hedge. The gate led into the lane. The May sunset was red in clouds, and there was still half an hour to twilight.The dry slope was dotted with rabbits -- some nibbling at the thin grass near their holes, others pushing further down to look for dandelions or perhaps a cowslip that the rest had missed. Here and there one sat upright on an ant heap and looked about, with ears erect and nose in the wind. But a blackbird, singing undisturbed on the outskirts of the wood, showed that there was nothing alarming there, and in the other direction, along the brook, all was plain to be seen, empty and quiet. The warren was at peace. At the top of the bank, close to the wild cherry where the blackbird sang, was a little group of holes almost hidden by brambles. In the green half-light, at the mouth of one of these holes, two rabbits were sitting together side by side. At length, the larger of the two came out, slipped along the bank under cover of the brambles and so down into the ditch and up into the field. A few moments later the other followed.";

int main(){

    int length;

    bool cont = true;
    while (cont){
        cout<<"Enter a length. Type -1 to exit."<<endl;
        cin >>length;
        cout<<"Initiating Search."<<endl;
        if (length == -1){
            exit(0);
        }
        int child = fork();
        if (child == 0){
            // in child
            istringstream stm(doc) ;
            string word ;
            vector<string> words;
            while( stm >> word ){
                words.push_back(word); //puts each word in a vector
            }
            bool found = false;
            int count = 0;
            while(!found){ //injected bug. If a word of that length is not found, then infinite loop
                cout<< "."<<endl;
                sleep(0.5);
                for ( const string& word: words){
                    if (word.size() == length){ //loops through vector, checks length
                        count++;
                        found = true;
                    }
                }
            }
            cout<<"Words of length "<<length<<": "<<count<<endl;

            exit(0);
        }
    
    }
  return 0;
}



