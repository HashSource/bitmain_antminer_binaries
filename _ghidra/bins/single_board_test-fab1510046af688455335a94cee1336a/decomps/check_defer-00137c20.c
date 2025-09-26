
void check_defer(int nid)

{
  if ((obj_cleanup_defer == 0) && (0x3bd < nid)) {
    obj_cleanup_defer = 1;
  }
  return;
}

