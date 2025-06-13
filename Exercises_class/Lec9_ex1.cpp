#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

class Shape {
protected:
    vector<pair<double, double>> vertices;

public:
    virtual ~Shape() {}
    virtual double area() const = 0;
    virtual void read(istream& is) = 0;
    virtual void write(ostream& os) const = 0;
    virtual char type() const = 0;
};

class Triangle : public Shape {
public:
    void read(istream& is) override {
        double x1, y1, x2, y2, x3, y3;
        is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        vertices.push_back(make_pair(x1, y1));
        vertices.push_back(make_pair(x2, y2));
        vertices.push_back(make_pair(x3, y3));
    }

    double area() const override {
        if (vertices.size() != 3) return 0;
        double x1 = vertices[0].first, y1 = vertices[0].second;
        double x2 = vertices[1].first, y2 = vertices[1].second;
        double x3 = vertices[2].first, y3 = vertices[2].second;
        return abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0);
    }

    void write(ostream& os) const override {
        os << "t ";
        for (size_t i = 0; i < vertices.size(); ++i) {
            os << vertices[i].first << " " << vertices[i].second << " ";
        }
    }

    char type() const override { return 't'; }
};

class Rectangle : public Shape {
public:
    void read(istream& is) override {
        double x1, y1, x2, y2;
        is >> x1 >> y1 >> x2 >> y2;
        vertices.push_back(make_pair(x1, y1));
        vertices.push_back(make_pair(x2, y2));
    }

    double area() const override {
        if (vertices.size() != 2) return 0;
        double width = abs(vertices[1].first - vertices[0].first);
        double height = abs(vertices[1].second - vertices[0].second);
        return width * height;
    }

    void write(ostream& os) const override {
        os << "r ";
        for (size_t i = 0; i < vertices.size(); ++i) {
            os << vertices[i].first << " " << vertices[i].second << " ";
        }
    }

    char type() const override { return 'r'; }
};

class Square : public Shape {
public:
    void read(istream& is) override {
        double x1, y1, x2, y2;
        is >> x1 >> y1 >> x2 >> y2;
        vertices.push_back(make_pair(x1, y1));
        vertices.push_back(make_pair(x2, y2));
    }

    double area() const override {
        if (vertices.size() != 2) return 0;
        double side = max(abs(vertices[1].first - vertices[0].first), 
                         abs(vertices[1].second - vertices[0].second));
        return side * side;
    }

    void write(ostream& os) const override {
        os << "s ";
        for (size_t i = 0; i < vertices.size(); ++i) {
            os << vertices[i].first << " " << vertices[i].second << " ";
        }
    }

    char type() const override { return 's'; }
};

class Parallelogram : public Shape {
public:
    void read(istream& is) override {
        double x1, y1, x2, y2, x3, y3;
        is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        vertices.push_back(make_pair(x1, y1));
        vertices.push_back(make_pair(x2, y2));
        vertices.push_back(make_pair(x3, y3));
    }

    double area() const override {
        if (vertices.size() != 3) return 0;
        double x1 = vertices[0].first, y1 = vertices[0].second;
        double x2 = vertices[1].first, y2 = vertices[1].second;
        double x3 = vertices[2].first, y3 = vertices[2].second;
        return abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
    }

    void write(ostream& os) const override {
        os << "p ";
        for (size_t i = 0; i < vertices.size(); ++i) {
            os << vertices[i].first << " " << vertices[i].second << " ";
        }
    }

    char type() const override { return 'p'; }
};

Shape* createShape(char type) {
    switch (tolower(type)) {
        case 't': return new Triangle();
        case 'r': return new Rectangle();
        case 's': return new Square();
        case 'p': return new Parallelogram();
        default: return nullptr;
    }
}

vector<Shape*> readShapesFromFile(const string& filename) {
    ifstream inputFile(filename);
    vector<Shape*> shapes;
    
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return shapes;
    }
    
    int numShapes;
    inputFile >> numShapes;
    
    string line;
    getline(inputFile, line); 
    
    for (int i = 0; i < numShapes; ++i) {
        getline(inputFile, line);
        istringstream iss(line);
        
        char shapeType;
        iss >> shapeType;
        
        Shape* shape = createShape(shapeType);
        if (shape) {
            shape->read(iss);
            shapes.push_back(shape);
        } else {
            cerr << "Error: Unknown shape type '" << shapeType << "'" << endl;
        }
    }
    
    inputFile.close();
    return shapes;
}

void writeShapesToFile(const string& filename, const vector<Shape*>& shapes) {
    ofstream outputFile(filename);
    
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }
    
    outputFile << shapes.size() << endl;
    
    vector<Shape*> sortedShapes = shapes;
    sort(sortedShapes.begin(), sortedShapes.end(), 
        [](Shape* a, Shape* b) { return a->area() > b->area(); });
    
    for (size_t i = 0; i < sortedShapes.size(); ++i) {
        sortedShapes[i]->write(outputFile);
        outputFile << "-> " << fixed << setprecision(2) << sortedShapes[i]->area() << endl;
    }
    
    outputFile.close();
}

void printShapes(const vector<Shape*>& shapes) {
    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << "Shape type: ";
        switch (shapes[i]->type()) {
            case 't': cout << "Triangle"; break;
            case 'r': cout << "Rectangle"; break;
            case 's': cout << "Square"; break;
            case 'p': cout << "Parallelogram"; break;
        }
        cout << endl << "Vertices: ";
        shapes[i]->write(cout);
        cout << endl << "Area: " << shapes[i]->area() << endl << endl;
    }
}

int main() {
    string inputFilename = "D:/University/2nd YEAR (2024 - 2025)/2nd Sem/Programming 2/Exercise/input.txt.txt";
    string outputFilename = "output.txt";
    
    vector<Shape*> shapes = readShapesFromFile(inputFilename);
    
    cout << "Read " << shapes.size() << " shapes from file." << endl << endl;
    printShapes(shapes);
    
    writeShapesToFile(outputFilename, shapes);
    cout << "Shapes written to " << outputFilename << " sorted by area." << endl;
    
    for (size_t i = 0; i < shapes.size(); ++i) {
        delete shapes[i];
    }
    
    return 0;
}