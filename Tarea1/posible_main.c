#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int main(int argc, const char * argv[]) {

    while (readCommand()) {

    }


    return 0;
}

int readCommand(){
    char command[4];
    int gravity;
    char name[32];
    scanf("%s",command);

    if (!strcmp(command,"NEW")){
        scanf("%s",name);
        scanf("%d",&gravity);
        Persona* personaCreada = malloc(sizeof(Persona));
        personaCreada -> name = malloc(sizeof(char)*(strlen(name)+1));
        personaCreada -> gravity = gravity;
        add(personaCreada);

    }
    else if (!strcmp(command,"NXT")) {

    }
    else if (!strcmp(command,"UPD")) {
        scanf("%s",name);
        scanf("%d",&gravity);

    }
    else if (!strcmp(command,"DIE")) {
        return 0;
    }
    else {

    }
    return 1;
}
