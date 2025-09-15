
int fix_hash_rate(int hashrateGH)

{
  int hashrateGH_local;
  
  return ((hashrateGH + -100) / 500) * 500;
}

