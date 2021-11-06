//
// Name: Ozan Mirza
// Date: November 4th, 2021
// Program: "Radish Pie: Extra Credit"
// Eventual Discovery: This list of instructions is the algorithm to finding the square root of a #.
//

// Use programming to solve this problem (and display the answer): 3^1(/2)
#include <iostream>

// I recently came across a rather peculiar recipe for something called Babylonian radish pie. Intrigued, I began to follow the directions, which said I could start with any number of cups of flour.
int starting_cups_of_flour = 0;

// Any number? I mean, I had to start with some flour, so zero cups wasn’t an option. But according to the recipe, any positive value was fair game. Next, I needed a second amount of flour that was 3 divided by my original number. For example, if I had started with two cups of flour, then the recipe told me I now needed 3 divided by 2, or 1.5, cups at this point.
double generate_next_cups_of_flour(double cups_of_flour) {
    return 3 / cups_of_flour;
}

// I was then instructed to combine these amounts of flour and discard half. Apparently, this was my new starting amount of flour. I was to repeat the process, combining this amount with 3 divided by it and then discarding half.
double combine_discard_half(double cups_of_flour, double next_cups_of_flour) {
    return (cups_of_flour + next_cups_of_flour) / 2;
}

// The recipe told me to keep doing this, over and over. Eventually, I’d have the proper number of cups of flour for my radish pie.
double calculate_cups_of_flour_needed_to_make_radish_pie(double cups_of_flour) {
    double next_cups_of_flour = generate_next_cups_of_flour(cups_of_flour);
    double new_cups_of_flour = combine_discard_half(cups_of_flour, next_cups_of_flour);
    if (abs(new_cups_of_flour - cups_of_flour) > 0.0001) {
        return calculate_cups_of_flour_needed_to_make_radish_pie(new_cups_of_flour);
    }
    return new_cups_of_flour;
}

// How many cups of flour does the recipe ultimately call for?
int main() {
    while (!(starting_cups_of_flour > 0)) {
        std::cout << "How many cups of flour do you want to start with? ";
        std::cin >> starting_cups_of_flour;
        if (starting_cups_of_flour <= 0) {
            std::cout << "Can you have a negative or no amount of flour? Is that physically possible? Let's choose an number of cups of flour that can exist in this plane of reaity!";
            std::cout << "\n";
        }
    }
    std::cout << "You need approximately ";
    std::cout << calculate_cups_of_flour_needed_to_make_radish_pie(starting_cups_of_flour);
    std::cout << " many cups of flour to make a Radish Pie.";
    std::cout << "\n";
}