// dsa course project
// team details

// metro station of metropolitian city
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define max 30
#define INFINITY 999999
#define INT_MAX 1000003

// print all name of station😀😀
void callcity(char array[56][100])
{
    printf("List of metro station\n");
    for (int i = 0; i < 56; i++)
    {

        printf("%d.%s station\n", i + 1, array[i]);
    }

    return;
}

// single source single destination
void single_destin(int v, int graph[v][v], int src, int destination, char station[56][100])
{
    int cost[v][v], distance[v], visited[v], path[v];
    int nextnode;
    int count;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {

            if (graph[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = graph[i][j];
            }
        }
    }
    int mindistance;

    // creating distance visited path
    for (int i = 0; i < v; i++)
    {
        distance[i] = cost[src][i];
        path[i] = src;
        visited[i] = 0;
    }

    distance[src] = 0;
    visited[src] = 1;
    count = 1;

    while (count < v - 1)
    {
        mindistance = INFINITY;
        for (int i = 0; i < v; i++)
        {
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        // we have to extract all neigh
        for (int i = 0; i < v; i++)
        {
            if (mindistance + cost[nextnode][i] < distance[i] && !visited[i])
            {
                distance[i] = mindistance + cost[nextnode][i];
                path[i] = nextnode;
            }
        }
        count++;
    }

    printf("\nDistance from %s to %s: %d\n", station[src], station[destination], distance[destination]);
    return;
}

float to_min(float t)
{
    return t / 60;
}

void currenttime()
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("Current local time and date: %s", asctime(timeinfo));

    return;
}

void findtime(int d)
{
    //   average speed of train is 25m/s;
    float t = d / 25;

    printf("you will reach in %0.2f minutes\n", to_min(t));
    return;
}

void single_destcost(int v, int graph[v][v], int src, int destination, char station[56][100])
{
    int cost[v][v], distance[v], visited[v], path[v];
    int nextnode;
    int count;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {

            if (graph[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = graph[i][j];
            }
        }
    }
    int mindistance;

    // creating distance visited path
    for (int i = 0; i < v; i++)
    {
        distance[i] = cost[src][i];
        path[i] = src;
        visited[i] = 0;
    }

    distance[src] = 0;
    visited[src] = 1;
    count = 1;

    while (count < v - 1)
    {
        mindistance = INFINITY;
        for (int i = 0; i < v; i++)
        {
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        // we have to extract all neigh
        for (int i = 0; i < v; i++)
        {
            if (mindistance + cost[nextnode][i] < distance[i] && !visited[i])
            {
                distance[i] = mindistance + cost[nextnode][i];
                path[i] = nextnode;
            }
        }
        count++;
    }

    printf("-----------------------------details for metro---------\n");
    printf("From:%s\n", station[src]);
    printf("To:%s\n", station[destination]);
    float d = distance[destination];
    printf("distance:%0.2f km\n", d / 1000);
    // 2rs/1000=0.002;
    printf("cost:%0.2f\n", d * 0.002);
    currenttime();
    findtime(d);
    printf("---------------------------thankyou--------------------\n");

    return;
}

// helps to find the string
int find(char h[100], char array[56][100])
{
    for (int i = 0; i < 56; i++)
    {
        if (!strcmp(array[i], h))
        {
            return i;
            break;
        }
    }
}

// brutt-force-string-serach-algorithm
int bfss()
{
    char p[100];
    char t[100];
    int n = strlen(p);
    int m = strlen(t);
    int t1 = -2;
    for (int i = 0; i < (n - m) + 1; i++)
    {
        int j = 0;
        while (j < m && p[j] == t[j + i])
        {
            j++;
        }
        if (j == m)
            t1 = i;
    }
    if (t1 + 1 == 1)
    {
        return 1;
    }
    else
        return 0;
}

// single source multiple destination distance code
void multiple_destin(int v, int graph[56][56], int src, char array[56][100])
{
    int cost[v][v], distance[v], visited[v], path[v];
    int nextnode;
    int count;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {

            if (graph[i][j] == 0 && i != j)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = graph[i][j];
            }
        }
    }
    int mindistance;

    // creating distance visited path
    for (int i = 0; i < v; i++)
    {
        distance[i] = cost[src][i];
        path[i] = src;
        visited[i] = 0;
    }

    distance[src] = 0;
    visited[src] = 1;
    count = 1;

    while (count < v - 1)
    {
        mindistance = INFINITY;
        for (int i = 0; i < v; i++)
        {
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        // we have to extract all neigh
        for (int i = 0; i < v; i++)
        {
            if (mindistance + cost[nextnode][i] < distance[i] && !visited[i])
            {
                distance[i] = mindistance + cost[nextnode][i];
                path[i] = nextnode;
            }
        }
        count++;
    }

    for (int i = 0; i < v; i++)
    {
        if (i != src)
        {
            printf("\nDistance from %s to : %s:%d", array[src], array[i], distance[i]);
        }
    }
}

// it will find the minimum distance
int mindistance(int distance[], int stat[])
{
    int minimum = INT_MAX, ind;
    for (int k = 0; k < 56; k++)
    {
        if (stat[k] == 0 && distance[k] <= minimum)
        {
            minimum = distance[k];
            ind = k;
        }
    }
    return ind;
}

// counts the number of station between the source and destination
void count_source_to_dest(int graph[56][56], int source, char stations[55][100], int d)
{
    int distance[56];
    int stat[56];
    for (int k = 0; k < 56; k++)
    {
        distance[k] = INT_MAX;
        stat[k] = 0;
    }
    distance[source] = 0;
    for (int k = 0; k < 56; k++)
    {
        int m = mindistance(distance, stat);
        stat[m] = 1;
        for (int k = 0; k < 56; k++)
        {
            if (!stat[k] && graph[m][k] && distance[m] != INT_MAX && distance[m] + graph[m][k] < distance[k])
                distance[k] = distance[m] + graph[m][k];
        }
    }
    for (int k = 0; k < 56; k++)
    {
        if (k == d)

            printf("Minium stations from %s to %s are %d\n", stations[source], stations[k], distance[k]);
    }

    return;
}

// counts the station between the source and all station
void count_source_to_all(int graph[56][56], int source, char stations[55][100])
{
    int distance[56];
    int stat[56];
    for (int k = 0; k < 56; k++)
    {
        distance[k] = INT_MAX;
        stat[k] = 0;
    }
    distance[source] = 0;
    for (int k = 0; k < 56; k++)
    {
        int m = mindistance(distance, stat);
        stat[m] = 1;
        for (int k = 0; k < 56; k++)
        {
            if (!stat[k] && graph[m][k] && distance[m] != INT_MAX && distance[m] + graph[m][k] < distance[k])
                distance[k] = distance[m] + graph[m][k];
        }
    }

    printf("Minimum number of station from %s to every station\n ", stations[source]);
    for (int k = 0; k < 56; k++)
    {

        printf("Minium stations from %s to %s are %d\n", stations[source], stations[k], distance[k]);
    }
    return;
}

int main()
{
    // number of vertex
    int v = 56;

    // number of edge
    int e = 57;
    int graph[56][56];
    int graph01[56][56];
    // intailising the graph by file
    FILE *fp;
    // pointer to open a file
    fp = fopen("text.txt", "r");
    int temp;
    for (int i = 0; i < 56; i++)
    {
        for (int j = 0; j < 56; j++)
        {
            fscanf(fp, "%d", &temp);
            graph[i][j] = temp;
        }
    }
    // close the file
    fclose(fp);
    // intailising the graph by file
    FILE *fp1;
    // intailising the graph by file
    fp1 = fopen("text1.txt", "r");
    for (int i = 0; i < 56; i++)
    {
        for (int j = 0; j < 56; j++)
        {
            fscanf(fp1, "%d", &temp);
            graph01[i][j] = temp;
        }
    }
    // close the file
    fclose(fp1);
    // this source is always used for indexing
    int source;
    // indexing of destination
    int dest;
    // array of strings is represented by 2d array
    // the indexing gives the names of stations of city
    char array[56][100] = {"LBnagar", "Victoria_memorial", "chaitanyapuri", "Dilshukhnagar", "moosrambagh", "NewMarket", "malakpet", "MGbusstation", "Osmania_medical", "Gandhibhavan", "Nampally", "Assembly", "Lakdikapool", "Khairtabad", "Irrummanzil", "Panjagutta", "Ameerpet", "SRnagar", "ESIhospital", "Erragadda", "Bharatnagar", "Moosapet", "DR_BRambedkar", "Kukatpally", "KPHBcolony", "JNTUcollege", "Miyapur", "Sultanbazar", "Narayanguda", "Chikkadpali", "RTCxroads", "Musheerabad", "Gandhihospital", "Secbadwest", "Paradeground", "Nagole", "Uppal", "stadium", "NGRI", "Habsiguda", "Tarnaka", "Mettuguda", "Secbadeast", "Paradise", "Rasoolpura", "PrakashNagar", "Begumpet", "MathuraNagar", "Yusufguda", "Jubliehills", "JH-checkpost", "Peddamagudi", "Madhapur", "Dugamcheruvu", "Hitechcity", "raidurg"};
    char c1[100];
    char c2[100];
    // used for choice selection
    int choice;
    while (1)
    {
        printf("enter the choice\n");
        printf("Enter 1 for source to destination\n");
        printf("Enter 2 single source to multiple destination\n");
        printf("Enter 3 for number of station between source and destination\n");
        printf("Enter 4 for number of station between  source to multiple destination\n");
        printf("Enter 5 for details of the tour\n");
        printf("Enter 6 for path between source and destination\n");
        printf("Enter 7 for distance from one to all in sorted order\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            callcity(array);
            printf("Enter the source\n");
            fflush(stdin);
            gets(c1);
            source = find(c1, array);
            if (source == 0)
            {
                printf("Enter the correct spelling\n");
                printf("write again\n");
                continue;
            }
            printf("Enter the destination\n");
            fflush(stdin);
            gets(c2);
            dest = find(c2, array);
            if (dest == 0)
            {
                printf("Enter the correct spelling\n");
                printf("write again\n");
                continue;
            }
            single_destin(v, graph, source, dest, array);
            break;

        case 2:
            callcity(array);
            printf("Enter the source\n");
            fflush(stdin);
            gets(c1);
            source = find(c1, array);
            if (source == 0)
            {
                printf("Enter the correct spelling\n");
                printf("write again\n");
                continue;
            }
            multiple_destin(v, graph, source, array);
            break;

        case 3:
            callcity(array);
            printf("Enter the source\n");
            fflush(stdin);
            gets(c1);
            source = find(c1, array);
            if (source == 0)
            {
                printf("Enter the correct spelling\n");
                printf("write again\n");
                continue;
            }
            printf("Enter the destination\n");
            fflush(stdin);
            gets(c2);
            dest = find(c2, array);
            if (dest == 0)
            {
                printf("Enter the correct spelling\n");
                printf("write again\n");
                continue;
            }
            count_source_to_dest(graph01, source, array, dest);
            break;

        case 4:
            callcity(array);
            printf("Enter the source\n");
            printf("Enter the source\n");
            fflush(stdin);
            gets(c1);
            source = find(c1, array);
            if (source == 0)
            {
                printf("Enter the correct spelling\n");
                printf("write again\n");
                continue;
            }
            count_source_to_all(graph01, source, array);
            break;

        case 5:
            callcity(array);
            printf("Enter the source\n");
            fflush(stdin);
            gets(c1);
            source = find(c1, array);
            if (source == 0)
            {
                printf("Enter the correct spelling\n");
                printf("write again\n");

                continue;
            }

            printf("Enter the destination\n");
            fflush(stdin);
            gets(c2);
            dest = find(c2, array);
            if (dest == 0)
            {
                printf("Enter the correct spelling\n");
                printf("write again\n");
                continue;

            }
            single_destcost(v, graph, source, dest, array);
            break;

        case 6:
            callcity(array);
            printf("Enter the source\n");
            fflush(stdin);
            gets(c1);
            source = find(c1, array);
            if (source == 0)
            {
                printf("Enter the correct spelling\n");
                printf("write again\n");
                continue;
            }
            printf("Enter the destination\n");
            fflush(stdin);
            gets(c2);
            dest = find(c2, array);
            if (dest == 0)
            {
                printf("Enter the correct spelling\n");
                printf("write again\n");
                continue;
            }
            // krus(e, graph, array, source, dest);
        break;

        case 7:           
            callcity(array);
            printf("Enter the source\n");
            fflush(stdin);
            gets(c1);
            source = find(c1, array);
            if (source == 0)
            {
                printf("Enter the correct spelling\n");
                printf("write again\n");
                continue;
            }
            ptintf("In sorted manner\n");
            multiple_destin(v, graph, source, array);
        break;

        case 0:
            exit(0);
            break;

        default:
            printf("Enter the valid choice\n");
            break;

        }

    }

    return 0;
}
