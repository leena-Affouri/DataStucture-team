#include <stdio.h>
#include <stdlib.h>
#define MAX_IN_ROW 100 /// Maximum number of characters in  a line in file
typedef struct node_team *ptr_team;
struct node_team
{
    char name[20];
    char code[10];
    int noOfWins;
    int noOfDraws;
    int noOfLoses;
    int goalsDifference;
    ptr_team next;
};
typedef ptr_team team_list;
//This function is for inserting a new node at last and return this new node to be able to fill the data into it for team list
ptr_team create_node_team (team_list header){

    team_list position = header;
    while (position->next!= NULL){
            position = position->next;
    }
    team_list newNode = (struct node_course*)malloc(sizeof(struct node_course));
    position->next = newNode;
    newNode->next = NULL;
    return newNode;
}
 //This function is for dividing the array from file into tokens and fill these tokens into a node for team list
void divide_and_fill_team (team_list node ,char line[]){
   char *token = strtok(line,",");
    if (token!=NULL)
        //strcpy() function used to copy a string from the pointer to token
        strcpy(node->name,token);
    token = strtok(NULL, ",");
    if (token!=NULL)
        //strcpy() function used to copy a string from the pointer to token
        strcpy(node->code,token);
    //if the string is not fully tokenized.
    token = strtok(NULL, ",");
    if (token != NULL)
        //converts the string argument token to an integer .
        node->noOfWins= atoi(token);

    token = strtok(NULL, ",");
    if(token!=NULL)
        node->noOfDraws = atoi(token);

     token = strtok(NULL, ",");
    if (token != NULL)
        //converts the string argument token to an integer .
        node->noOfLoses= atoi(token);

     token = strtok(NULL, ",");
    if (token != NULL)
        //converts the string argument token to an integer .
        node->goalsDifference= atoi(token);
}
//This function is for creating nodes and fillig them for the array of linked list and the waiting list
void fill_array_of_list(team_list node, team_list team_position, int flagHead){
    if(flagHead){
        copy_team_node(node,team_position);
        node->next = NULL;
    }
    else{
        team_list newNode = create_node_team(node);
        copy_team_node(newNode,team_position);
    }
}
//This function is for copying the data from a team's node into a new node
void copy_team_node(team_list node, team_list team_node){
    strcpy(node->name,team_node->name);
    strcpy(node->code,team_node->code);
    node->noOfWins = team_node->noOfWins;
    node->noOfDraws = team_node->noOfDraws;
    node->noOfLoses = team_node->noOfLoses;
    node->goalsDifference = team_node->goalsDifference;

}

//This function is to show the menu
void displayChoices(){
    printf("Choose from the menu below:\n");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
}
//This function reads from file, saves the data correctly in a linked list and returns the actual number of team in the file
int read_and_print_teams_file(team_list team_header,char line_file_teams[MAX_IN_ROW]){
    // Declare a pointer of type file
    FILE *teams_file;
    teams_file = fopen("teams.txt","r");//open the file and read from it

    if (teams_file == NULL){
        printf("File does not exist");
        return (-1);
    }

    int numOfTeams= 1; //This counter to know the actual number of teams in the file
    fgets(line_file_teams,MAX_IN_ROW,teams_file);
    divide_and_fill_team(team_header,line_file_teams);  ///Here i filled in the header of team (linked)list

    // This loop is for reading from the file and saving the data into nodes until the end of the file
    while ((fgets(line_file_teams,MAX_IN_ROW,teams_file))!=NULL && teams_file !=EOF){
        numOfTeams++;
        team_list newNode= create_node_team(team_header);
        divide_and_fill_team(newNode,line_file_teams);
    }
         team_list temp;
         temp = team_header;

    for (int j = 0 ; j<numOfTeams ; j++){
        printf("%s\t %s\t %d\t%d\t %d\t\t%d\n", temp->name,temp->code ,temp->noOfWins, temp->noOfDraws ,temp->noOfLoses ,temp->goalsDifference);

        temp = temp->next;
    }
    fclose(teams_file);
    return numOfTeams;
}
int Points (team_list team_header ,int noOfWins , int noOfDraw)
{
    int points;

    Points = (3*noOfWins) + (1*noOfDraw);
}
int main()
{
     //Create a linked_lists for teams
    team_list team_header = (team_list*)malloc (sizeof(struct node_team));
    team_header->next=NULL;
    // This array is for reading each line in the file of teams
    char line_file_team[MAX_IN_ROW];

    return 0;
}
