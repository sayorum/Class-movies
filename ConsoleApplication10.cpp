#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Movie {
    string title;
    string genre;
    int rating;
    int year;
    double price;
};

const int MAX_MOVIES = 100;

int main() {
    Movie movies[MAX_MOVIES];
    int numMovies = 0;

    ifstream inputFile("movies.txt");
    if (!inputFile) {
        cout << "Failed to open movies.txt" << endl;
        return 1;
    }

    // Загрузка информации о фильмах из файла
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        if (numMovies >= MAX_MOVIES) {
            cout << "Exceeded maximum number of movies" << endl;
            break;
        }
        if (!(iss >> movies[numMovies].title >> movies[numMovies].genre >> movies[numMovies].rating >> movies[numMovies].year >> movies[numMovies].price)) {
            cout << "Error parsing movie information" << endl;
            break;
        }
        numMovies++;
    }

    inputFile.close();

    // Вывод информации о фильмах
    for (int i = 0; i < numMovies; i++) {
        cout << "Movie " << i + 1 << ":" << endl;
        cout << "Title: " << movies[i].title << endl;
        cout << "Genre: " << movies[i].genre << endl;
        cout << "Rating: " << movies[i].rating << " stars" << endl;
        cout << "Year: " << movies[i].year << endl;
        cout << "Price: " << movies[i].price << endl;
        cout << endl;
    }

    return 0;
}
