#define CYAN 3
#define RED 4
#define GREEN 10
#define WHITE 15
#define YELLOW 14


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 
inline void SET_CONSOLE_COLOR(int color) {
    SetConsoleTextAttribute(hConsole, color);
} 
inline void CLEAR_CONSOLE() {
    system("CLS");
}  

void WaitForKeyPress() {
    cout << "\nPress Enter to continue...";
    getch();
}