#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct movie
{
    int id;
    char name[50];
    float rating;
};

void addMovie()
{
    int fd = open("movies.dat", O_WRONLY | O_CREAT | O_APPEND, 0644);

    struct movie m;

    printf("Enter ID: ");
    scanf("%d", &m.id);

    printf("Enter Name: ");
    scanf("%s", m.name);

    printf("Enter Rating: ");
    scanf("%f", &m.rating);

    write(fd, &m, sizeof(m));
    close(fd);
}

void displayMovies()
{
    int fd = open("movies.dat", O_RDONLY);

    struct movie m;

    printf("\nMovie Records:\n");

    while(read(fd, &m, sizeof(m)) > 0)
    {
        if(m.id != -1)
        {
            printf("ID:%d Name:%s Rating:%.1f\n",
                   m.id, m.name, m.rating);
        }
    }

    close(fd);
}

void searchMovie()
{
    int fd = open("movies.dat", O_RDONLY);

    int id;
    struct movie m;

    printf("Enter ID: ");
    scanf("%d", &id);

    while(read(fd, &m, sizeof(m)) > 0)
    {
        if(m.id == id)
        {
            printf("Found: %s %.1f\n",
                   m.name, m.rating);
            break;
        }
    }

    close(fd);
}

void countMovies()
{
    int fd = open("movies.dat", O_RDONLY);

    struct movie m;
    int count = 0;

    while(read(fd, &m, sizeof(m)) > 0)
    {
        if(m.id != -1)
            count++;
    }

    printf("Total Records = %d\n", count);

    close(fd);
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1.Add Movie\n");
        printf("2.Display Movies\n");
        printf("3.Search Movie\n");
        printf("4.Count Movies\n");
        printf("5.Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addMovie();
                break;

            case 2:
                displayMovies();
                break;

            case 3:
                searchMovie();
                break;

            case 4:
                countMovies();
                break;

            case 5:
                return 0;
        }
    }
}
