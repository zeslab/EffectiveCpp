// ITEM 2: Prefer consts, enums, and inlines to #defines.

#if 0 
/// BAD APPROACH 

#include <iostream>
#include <cmath>

#define PI 3.14159
#define CIRCLE_AREA(radius) (PI * (radius) * (radius))
#define SQUARE 1
#define CIRCLE 2

int main() {
    int shape = CIRCLE;
    float radius = 5.0;

    if (shape == CIRCLE) {
        std::cout << "Circle area: " << CIRCLE_AREA(radius) << std::endl;
    }

    // Imagine a typo in shape comparison
    if (shape == SQUARE) {
        std::cout << "Square area (mistake): " << CIRCLE_AREA(radius) << std::endl;
    }

    return 0;
}
/*
Problems:

No type safety: The #define PI is just a text substitution. If you change the value to something incompatible or use a wrong type (e.g., a string), the compiler won't catch it.
Debugging issues: The macro CIRCLE_AREA(radius) is difficult to trace in debugging because it's expanded at the preprocessor level.
No scoping: #define SQUARE and #define CIRCLE are global and may lead to naming collisions.
Potential bugs: CIRCLE_AREA(radius) is evaluated as a simple expression without considering the type, and can lead to unexpected behavior if radius is not handled properly (like if radius++ is used).
*/


#else 
// improved approach
#include <iostream>
#include <cmath>

// Use const instead of #define for constants
const double PI = 3.14159;

// Inline function instead of a macro
inline double calculateCircleArea(double radius) {
    return PI * radius * radius;
}

// Use enum class instead of #define for constants
enum class ShapeType {
    Square,
    Circle
};

int main() {
    ShapeType shape = ShapeType::Circle;
    double radius = 5.0;

    if (shape == ShapeType::Circle) {
        std::cout << "Circle area: " << calculateCircleArea(radius) << std::endl;
    }

    // A typo in shape comparison is caught by the compiler
    if (shape == ShapeType::Square) {
        std::cout << "Square area (mistake): " << calculateCircleArea(radius) << std::endl;
    }

    return 0;
}

/*
Prefer consts, enums, and inlines to #defines.
This Item might better be called “prefer the compiler to the preprocessor,”
*/

#endif
