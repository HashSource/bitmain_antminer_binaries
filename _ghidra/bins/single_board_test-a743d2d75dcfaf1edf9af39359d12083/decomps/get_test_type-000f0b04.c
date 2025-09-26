
char * get_test_type(char *log_name)

{
  char *pcVar1;
  char *log_name_local;
  
  pcVar1 = strstr(log_name,"PT2");
  if (pcVar1 == (char *)0x0) {
    pcVar1 = strstr(log_name,"PT1new");
    if (pcVar1 == (char *)0x0) {
      pcVar1 = strstr(log_name,"SWEEP");
      if (pcVar1 == (char *)0x0) {
        pcVar1 = strstr(log_name,"PT3");
        if (pcVar1 == (char *)0x0) {
          pcVar1 = strstr(log_name,"PT1&PT3");
          if (pcVar1 == (char *)0x0) {
            pcVar1 = (char *)0x0;
          }
          else {
            pcVar1 = "PT1&PT3";
          }
        }
        else {
          pcVar1 = "PT3";
        }
      }
      else {
        pcVar1 = "SWEEP";
      }
    }
    else {
      pcVar1 = "PT1new";
    }
  }
  else {
    pcVar1 = "PT2";
  }
  return pcVar1;
}

