
void add_point(int *point,int MAX_SIZE)

{
  int MAX_SIZE_local;
  int *point_local;
  
  *point = *point + 1;
  if (MAX_SIZE <= *point) {
    *point = 0;
  }
  return;
}

