//
// Created by ansarimn on 11/14/23.
//

#ifndef JSON_JSON0_H
#define JSON_JSON0_H

#endif //JSON_JSON0_H




#include <stdio.h>
#include <malloc.h>
#include <cJSON/cJSON.c>
#include <string.h>






cJSON * add_entry (int a) {
    struct cJSON * js0;
    char site [20], website [20], password [20], date [20];

    printf ("\nsite: ");
    scanf (" %19[^\n]", site);
    printf ("website: ");
    scanf (" %19[^\n]", website);
    printf ("password: ");
    scanf (" %19[^\n]", password);
    printf ("date: ");
    scanf (" %19[^\n]", date);


    js0 = cJSON_CreateObject ();
    cJSON_AddStringToObject (js0, "site", site);
    cJSON_AddStringToObject (js0, "website", website);
    cJSON_AddStringToObject (js0, "password", password);
    cJSON_AddStringToObject (js0, "date", date);


    char * json_str = cJSON_Print (js0);
    FILE * fp;
    //fp = fopen_s ("data.json", "w+");
    fp = fopen ("//home//ansarimn//CLionProjects//JSON//data.json", "a");

    if (fp == NULL) {
        printf ("\nerror in opening file;");
    }


    fputs ("\"", fp);
    fputs (site, fp);
    fputs ("\":\n", fp);
    fputs (json_str, fp);

    // a = 1 implies entries are not last entry
    if (a == 1) {
        fputs(",\n\n\n", fp);
    }

    else {
        char a [] = "\n}\n}";
        fputs (a, fp);
    }

    fclose (fp);


    /*
    cJSON_free (json_str);
    cJSON_Delete (js0);
    */

    return js0;
}




void print_json () {
    // open the file
    FILE *fp = fopen ("//home//ansarimn//CLionProjects//JSON//data.json", "r");

    if (fp == NULL) {
        printf("Error: Unable to open the file.\n");
    }


    // read the file contents into a string
    char buffer[1024];
    fread (buffer, 1, sizeof(buffer), fp);
    fclose(fp);


    // parse the JSON data
    //cJSON *json = cJSON_Parse (buffer);
    printf ("\n%s", buffer);

}




void init_file () {
    FILE * fp;
    char a [] = "{\n\"array\": {\n\n\n";

    fp = fopen ("//home//ansarimn//CLionProjects//JSON//data.json", "w");

    if (fp == NULL) {
        printf ("\nerror in opening file;");
    }


    fputs (a, fp);
    fclose (fp);
}




void close_file () {
    FILE * fp;
    char a [] = "\n}\n}";

    fp = fopen ("//home//ansarimn//CLionProjects//JSON//data.json", "a");

    if (fp == NULL) {
        printf ("\nerror in opening file;");
    }


    fputs (a, fp);
    fclose (fp);
}




void menu () {
    int option;

    //use options 1. and 2. only once;
    //there is no guarantee that 1. and 2.
    //will be executed exactly once;

    for (;;)
    {

        printf("1. Start operation\n");
        //printf("2. Terminate\n");
        printf("3. Exit\n");
        printf("4. Add new entries\n");
        printf("5. Add last entry\n");
        printf("6. Print entire file\n");
        scanf("%d[^\n]", &option);

        switch (option) {
            case 1:
                init_file();
                break;

            /*case 2:
                close_file();
                exit(0);*/

            case 3:
                exit (0);

            case 4:
                add_entry(1);
                break;

            case 5:
                add_entry(0);
                break;

            case 6:
                print_json ();
                break;
        }
    }
}