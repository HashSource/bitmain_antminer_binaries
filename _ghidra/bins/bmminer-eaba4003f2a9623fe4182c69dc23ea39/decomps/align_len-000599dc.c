
void align_len(size_t *len)

{
  size_t *len_local;
  
  if ((*len & 3) != 0) {
    *len = (*len & 0xfffffffc) + 4;
  }
  return;
}

