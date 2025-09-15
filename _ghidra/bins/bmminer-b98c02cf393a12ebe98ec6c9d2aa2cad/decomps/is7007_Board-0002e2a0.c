
bool is7007_Board(void)

{
  if (is7007_ctrl_board != -1) {
    return is7007_ctrl_board == 1;
  }
  isC5_Board();
  return is7007_ctrl_board == 1;
}

