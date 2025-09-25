
long get_abs_seconds(char *date)

{
  time_t tVar1;
  char *date_local;
  tm_conflict tm;
  time_t t;
  
  strptime(date,"%d %b %Y %H:%M:%S",(tm *)&tm);
  tm.tm_isdst = 0;
  tVar1 = mktime((tm *)&tm);
  return tVar1;
}

