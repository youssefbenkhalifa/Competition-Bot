#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int find(char **spells, int num_spells,  char **array,int num_array, char * word){
    for(int i=0;i<num_spells;i++){
        if(strcmp(spells[i],word)==0){
            return i;
        }
    }
    return -1;
}
bool contains(char **array, char string[],int n)
{
    for (int i = 1; i <=n; i++)
    {
        if (strcmp(array[i], string) == 0)
        { // strcmp compares two strings, returns 0 if they're equal, 1/-1 otherwise.
            return true;
        }
    }
    return false;
}

int occurrencesNotUsed(char letter, char **spells, char **usedSpells, int n , int j){
    int count=0;
     for (int i = 1; i <= n; i++) {
        if( !contains(usedSpells,spells[i],j)){
        size_t length = strlen(spells[i]);
        char firstChar = spells[i][0];
          if(firstChar==letter){
            count++;
          }
        }
    }
    return count;
}
int occu(char letter, char **spells, int n){
    int count=0;
     for (int i = 1; i <= n; i++) {
        size_t length = strlen(spells[i]);
        char firstChar = spells[i][0];
          if(firstChar==letter){
            count++;
          }
        }
    return count;
}
int cast_spell_MRYD(char **spells, int num_spells,char *previous ,  char **usedSpells,int num_used_spells) {

    char letter = previous[strlen(previous)-1];       
    char **notUsed;
    int occ[num_spells];
    int j=0;

    for(int i=1;i<num_spells;i++){
        if(contains(usedSpells,spells[i],num_used_spells)==false && spells[i][0]==letter){
            j++;
            strcpy(notUsed[j],spells[i]);
        }
    }
    if(strcmp(previous,"")==0 || j==0){
        for(int i=1;i<num_spells;i++){
                occ[i] = occu(spells[i][strlen(spells[i])-1],spells,num_spells);
            }
            int min = 1;
            for(int i=2;i<=num_spells;i++){
                if(occ[i]<occ[min]){
                    min = i;
                }
            }
            return min;
    }
       
        for(int i=1;i<j;i++){
            occ[i] = occurrencesNotUsed(notUsed[i][strlen(notUsed[i])-1],spells,usedSpells,num_spells,num_used_spells);
            if(occ[i]==0){
                // That's a direct win
                return find(spells,num_spells,notUsed,j,notUsed[i]);
            }
        }
        int min = 1;
        for(int i=2;i<j;i++){
            if(occ[i]<occ[min]){
                min = i;
            }
        }
        return find(spells,num_spells,notUsed,j,notUsed[min]);
            
  
}
int main(){
    char spells[11][50] = {"awesome","daf","efsdf","fdsfs","efcs","efsaq","wqfa","eqda","olla","eawfc","zdfe"};
    char usedspells[1][50] = "daf";
    int c = cast_spell_MRYD(**usedspells,11,"daf",**usedspells,1) ;
    printf("%s",spells[c]);
}
