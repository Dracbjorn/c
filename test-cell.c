/*
An example of a more complex cell.

As its name suggests, the cell will eat at surrounding enemy cells if 
possible, otherwise it rest until it reaches an energy threshold, then
chooses a random direction to run until it hits a minimum energy threshold.

This sequence allows the cell to spread out like a gas, filling space
faster than most other cells.  Once surrounding its enemy it can
nibble away from all directions, allowing it to defeat even the energy 
conservative Slime Mold example cell.
*/

#include <stdlib.h>

char *cell_name() {
  return "Destrominate";
}

static uint8_t MoveDirections[4]={LEFT,UP,RIGHT,DOWN};
static int init=0;

uint8_t cell_decide_action(uint8_t *env, int energy, uint64_t *memory) {
    
    int i,dir;
    uint8_t PossibleDir[4];
    int nPossibleDir;

    if(!init) {
        srand(env[CENTER]); //seed based on our player number
        init=1;
    }

    // Use memory to save state as follows:
    //    0 = resting state
    //    1 = just chose split action last turn
    //   >1 = running state, the value is a saved move action
    
    //Checks all 4 directions to see if enemy is present
    //If enemy exists, eat them
    for (i=0;i<4;i++) {
        dir=MoveDirections[i];
        if(isEnemy(dir))
            return EAT_BASE+dir;
    }

    // if energy is less than 40 then start resting
    if (energy<40) {
        *memory=0;
        return REST;
    }

    // if in resting state, continue to sleep until fully rested
    if(*memory==0 && energy<120)
        return REST;

    // now that we're rested, divide then run

    // if running direction already chosen, just do it
    if(*memory>1)
        return *memory;

    // list the directions empty near us
    nPossibleDir=0;
    for (i=0;i<4;i++) {
        dir=MoveDirections[i];
        if(isEmpty(dir))
            PossibleDir[nPossibleDir++]=dir;    
    }
    
    // if there's no room to move, REST
    if(nPossibleDir==0)
        return REST;

    // randomly choose an available direction
    dir=PossibleDir[rand()%nPossibleDir];

    // if just finished resting, time to divide
    if(*memory==0) {
        *memory=1; // state = "just split", run next time        
        return SPLIT_BASE+dir;
    }

    // must be in "just split" state (*memory=1)
    // now run in the random direction
    *memory=MOVE_BASE+dir;
    return MOVE_BASE+dir;
}