/*
 * Singleton class that allows the user to manipulate the terminal cursor position as well as the
 * color of the text produced.
 */
#ifndef TMANIP_H
#define TMANIP_H

#include <string>
#include <iostream>

class Cursor {
		public:
				static Cursor *getInstance() {
						if (NULL == single) {
								single = new Cursor();
						}
						return single;
				}
				~Cursor() {
						delete single;
				}
				void to(int x, int y) {
						//Move the cursor to the xth column and yth row.
						auto ys = std::to_string(y);
						auto xs = std::to_string(x);
						std::string str = "\e[" + ys + ";" + xs + "H";
						std::cout << str;
				}
				void up(int x) {
						//Move the cursor up x rows.
						auto xs = std::to_string(x);
						std::cout << "\e[" + xs + "A";
				}
				void down(int x) {
						//Move the cursor down x rows.
						auto xs = std::to_string(x);
						std::cout << "\e[" + xs + "B";
				}
				void forward(int x) {
						//Moves the cursor forward x columns.
						auto xs = std::to_string(x);
						std::cout << "\e[" + xs + "C";
				}
				void backward(int x) {
						//Move the cursor backwards x columns.
						auto xs = std::to_string(x);
						std::cout << "\e[" + xs + "D";
				}
				void save() {
						//Save the current cursor position.
						std::cout << "\e[s";
				}
				void restore() {
						//Returns to the position saved by Cursor::save
						std::cout << "\e[u";
				}
				void erase_line() {
						//Clears all characters from the cursor position to the end of the line
						//(including the character at the cursor position).
						std::cout << "\e[K";
				}
				void bold() {
						std::cout << "\e[1m";
				}
				void dim() {
					std::cout << "\e[2m";
				}
				void italic() {
					std::cout << "\e[3m";
				}
				void underline() {
					std::cout << "\e[4m";
				}
				void blink() {
					std::cout << "\e[5m";
				}
				void invert() {
					std::cout << "\e[7m";
				}
				void unset_all() {
					std::cout << "\e[0m";
				}
				void unset_bold() {
					std::cout << "\e[21m";
				}
				void unset_dim() {
					std::cout << "\e[22m";
				}
				void unset_underline() {
					std::cout << "\e[24m";
				}
				void unset_blink() {
					std::cout << "\e[25m";
				}
				void unset_inverse() {
					std::cout << "\e[27m";
				}
				void clear_screen() {
						//Clear screen.
						std::cout << "\e[2J";
				}
				void fg(int r, int g, int b) {
						//Set the foreground color to rgb(r,g,b).
						auto rs = std::to_string(r);
						auto gs = std::to_string(g);
						auto bs = std::to_string(b);
						std::cout << "\x1b[38;2;" + rs + ";" + gs + ";" + bs + "m";
				}
				void bg(int r, int g, int b) {
						//Set the background color to rgb(r,g,b).
						auto rs = std::to_string(r);
						auto gs = std::to_string(g);
						auto bs = std::to_string(b);
						std::cout << "\x1b[48;2;" + rs + ";" + gs + ";" + bs + "m";
				}
		private:
				Cursor (){}
				//copy constructor
				//Cursor(const Cursor & obj){}
				static Cursor *single;
};
Cursor *Cursor::single = 0;
//to get the singleton instance of the Cursor class
//Cursor* cur = Cursor::getInstance();
#endif
