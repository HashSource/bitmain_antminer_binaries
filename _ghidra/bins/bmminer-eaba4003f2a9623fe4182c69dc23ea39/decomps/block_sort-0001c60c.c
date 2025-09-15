
int block_sort(block *blocka,block *blockb)

{
  block *blockb_local;
  block *blocka_local;
  
  return blocka->block_no - blockb->block_no;
}

