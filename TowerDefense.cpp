#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include<algorithm>

struct Node {
    int x, y;
    float gCost, hCost, fCost;
    Node* parent;

    Node(int x, int y) : x(x), y(y), gCost(0), hCost(0), fCost(0), parent(nullptr) {}

    bool operator>(const Node& other) const {
        return fCost > other.fCost;
    }
};

class Pathfinding {
public:
    std::vector<Node> findPath(const std::vector<std::vector<int>>& grid, Node start, Node goal) {
        std::priority_queue<Node, std::vector<Node>, std::greater<Node>> openList;
        std::vector<std::vector<bool>> closedList(grid.size(), std::vector<bool>(grid[0].size(), false));

        openList.push(start);

        while (!openList.empty()) {
            Node current = openList.top();
            openList.pop();

            if (current.x == goal.x && current.y == goal.y) {
                return reconstructPath(current);
            }

            closedList[current.x][current.y] = true;

            for (auto& neighbor : getNeighbors(current, grid)) {
                if (closedList[neighbor.x][neighbor.y]) continue;

                float tentative_gCost = current.gCost + distance(current, neighbor);
                if (tentative_gCost < neighbor.gCost || !inOpenList(openList, neighbor)) {
                    neighbor.gCost = tentative_gCost;
                    neighbor.hCost = distance(neighbor, goal);
                    neighbor.fCost = neighbor.gCost + neighbor.hCost;
                    neighbor.parent = new Node(current);

                    openList.push(neighbor);
                }
            }
        }

        return {};
    }

private:
    std::vector<Node> getNeighbors(const Node& node, const std::vector<std::vector<int>>& grid) {
        std::vector<Node> neighbors;
        // Add logic for getting valid neighbors (adjacent nodes)
        return neighbors;
    }

    float distance(const Node& a, const Node& b) {
        return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
    }

    std::vector<Node> reconstructPath(Node current) {
        std::vector<Node> path;
        while (current.parent != nullptr) {
            path.push_back(current);
            current = *current.parent;
        }
        std::reverse(path.begin(), path.end());
        return path;
    }

    bool inOpenList(const std::priority_queue<Node, std::vector<Node>, std::greater<Node>>& openList, const Node& node) {
        // Add logic to check if a node is in the open list
        return false;
    }
};
