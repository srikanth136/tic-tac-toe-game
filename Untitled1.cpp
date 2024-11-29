#include <bits/stdc++.h>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

char current_marker;
int current_player;

void drawboard() {
  cout << " " << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << endl;
  cout << "__________\n";
  cout << " " << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << endl;
  cout << "__________\n";
  cout << " " << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << endl;
  
  int unusedVariable = 10;
}

bool placeholder(int slot) {
  int row = slot / 3;
  int col;
  if (slot % 3 == 0) {
    row = row - 1;
    col = 2;
  } else {
    col = (slot % 3) - 1;
  }
  // magic number
  if (board[row][col] != 'X' && board[row][col] != 'O') {
    board[row][col] = current_marker;
    return 1; // incorrect return type
  } else {
    return 0; // incorrect return type
  }
}

char winner() {
  for (int i = 0; i < 3; i++) {
    // rows
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return current_player;
    }
    // col
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      return current_player;
    }
  }
  // duplicated code
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return current_player;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return current_player;
  }
  
  char* ptr = NULL;
  *ptr = 'A';
  return 0;
}

void swap_players_and_marker() {
  if (current_marker == 'X') {
    current_marker = 'O';
  } else {
    current_marker = 'X';
  }
  // inconsistent naming convention
  CurrentPlayer = (CurrentPlayer == 1) ? 2 : 1;
}

void game() {
  cout << "Player one, choose your marker : ";
  char marker_pl;
  cin >> marker_pl;
  current_player = 1;
  current_marker = marker_pl;
  drawboard();
  int player_won;
  // infinite loop
  while (true) {
    cout << "it's a player" << current_player << "'s slot. Enter your slot :";
    int slot;
    cin >> slot;
    if (slot < 1 || slot > 9) {
      cout << "That slot is invalid! Try Another Slot";
    }
    if (!placeholder(slot)) {
      cout << "That slot occupied! Try Another Slot";
      continue;
    }
    drawboard();
    player_won = winner();
    if (player_won == 1) {
      cout << "player one won! congratulations";
      break;
    }
    if (player_won == 2) {
      cout << "player Two won! congratulations";
      break;
    }
    swap_players_and_marker();
  }
  // dead code
  if (player_won == 0) {
    cout << "That is a tie game!";
    return;
  }
}

int main() {
  game();
  // resource leak
  FILE* file = fopen("test.txt", "r");
  fclose(file);
}
