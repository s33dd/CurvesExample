#define _USE_MATH_DEFINES

#include <iostream>
#include "CurvesLibrary/CurvesLibrary.h"
#include <random>
#include <cmath>
#include <iomanip>

int main() {
    std::vector<std::unique_ptr<Shape>> randomShapes;

    std::random_device rd;

    //Change nums for different borders of random generator

    std::uniform_int_distribution<int> randInt(7, 19);
    std::uniform_real_distribution<double> randDouble(0.0, 180.0);
    std::uniform_int_distribution<int> shapeElection(1, 3);

    int vecSize = randInt(rd);

    //filling of the vector of random shapes with random params
    for (int i = 0; i < vecSize; i++) {
        switch (shapeElection(rd)) {
            case 1: //for cirle
                randomShapes.push_back(std::make_unique<Circle>(randDouble(rd)));
                break;
            case 2: //for ellipse
                randomShapes.push_back(std::make_unique<Ellipse>(randDouble(rd), randDouble(rd)));
                break;
            case 3: //for Helix
                randomShapes.push_back(std::make_unique<Helix>(randDouble(rd), randDouble(rd)));
                break;
        }
    }

    double t = M_PI / 4; //Value of param t in task
    std::vector<Circle*> circles;

    for (int i = 0; i < randomShapes.size(); i++) {
        std::vector<double> point, derivative;
        point = randomShapes[i]->GetPoint(t);
        derivative = randomShapes[i]->GetFirstDerivative(t);
        std::cout << "Shape " << i << " :" << std::endl <<
            "Point at t = PI/4:  " << "X:" << point[0] <<
            " Y: " << point[1] << " Z: " << point[2] << std::endl <<
            "Derivative at t = PI/4: <" << derivative[0] << " ," << derivative[1] <<
            " ," << derivative[2] << ">" << std::endl << std::endl;
        Circle* circlePtr = nullptr;
        if ( circlePtr = dynamic_cast<Circle*>(randomShapes[i].get())) {
            circles.push_back(circlePtr);
        }
    }
}
