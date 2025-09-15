
void store_mhashrate_history(double thash)

{
  FILE *pFVar1;
  double thash_local;
  FILE *pFile_1;
  FILE *pFile;
  
  if (0x40 < thash_index) {
    thash_index = 0;
  }
  if (3 < log_level) {
    pFVar1 = fopen(hash_log,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%d minutes countue...\n",store_mhashrate_history::minutes);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(hash_log,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"[%d] array\n",thash_index);
    }
    fclose(pFVar1);
  }
  thashrate_array[thash_index] = thash;
  store_mhashrate_history::minutes = store_mhashrate_history::minutes + 1;
  length = length + 1;
  if (0x40 < length) {
    length = 0x41;
  }
  return;
}

