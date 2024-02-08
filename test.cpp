#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Définition de la classe Agent
class Agent {
public:
    Agent(int type) : type(type) {}

    int getType() const {
        return type;
    }

private:
    int type; // 0 ou 1, représentant les deux types d'agents
};

// Fonction pour initialiser la grille avec des agents
void initGrid(std::vector<std::vector<Agent>>& grid, int rows, int cols, double density) {
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < rows; ++i) {
        std::vector<Agent> row;
        for (int j = 0; j < cols; ++j) {
            if (static_cast<double>(rand()) / RAND_MAX < density) {
                row.emplace_back(rand() % 2);
            } else {
                row.emplace_back(-1); // -1 représente une cellule vide
            }
        }
        grid.push_back(row);
    }
}

// Fonction pour afficher la grille
void printGrid(const std::vector<std::vector<Agent>>& grid) {
    for (const auto& row : grid) {
        for (const auto& agent : row) {
            if (agent.getType() == -1) {
                std::cout << "- "; // Cellule vide
            } else {
                std::cout << agent.getType() << " ";
            }
        }
        std::cout << std::endl;
    }
}

// Fonction pour mettre à jour la grille selon le modèle de Schelling
void updateGrid(std::vector<std::vector<Agent>>& grid, double satisfactionThreshold) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j].getType() != -1) {
                int similarNeighbors = 0;
                int totalNeighbors = 0;

                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        int ni = i + dx;
                        int nj = j + dy;

                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj].getType() != -1) {
                            ++totalNeighbors;
                            if (grid[i][j].getType() == grid[ni][nj].getType()) {
                                ++similarNeighbors;
                            }
                        }
                    }
                }

                double satisfaction = static_cast<double>(similarNeighbors) / totalNeighbors;

                if (satisfaction < satisfactionThreshold) {
                    // L'agent n'est pas satisfait, recherche d'une cellule vide pour se déplacer
                    for (int ni = 0; ni < rows; ++ni) {
                        for (int nj = 0; nj < cols; ++nj) {
                            if (grid[ni][nj].getType() == -1) {
                                std::swap(grid[i][j], grid[ni][nj]);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    const int rows = 10;
    const int cols = 10;
    const double density = 0.6;
    const double satisfactionThreshold = 0.3;

    std::vector<std::vector<Agent>> grid;

    initGrid(grid, rows, cols, density);

    std::cout << "Initial grid:" << std::endl;
    printGrid(grid);

    for (int iteration = 1; iteration <= 100000; ++iteration) {
        updateGrid(grid, satisfactionThreshold);

        std::cout << "\nGrid after iteration " << iteration << ":" << std::endl;
        printGrid(grid);
    }

    return 0;
}
