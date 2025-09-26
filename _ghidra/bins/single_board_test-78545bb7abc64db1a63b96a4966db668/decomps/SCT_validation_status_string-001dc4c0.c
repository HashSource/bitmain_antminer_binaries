
char * SCT_validation_status_string(void)

{
  undefined4 uVar1;
  
  uVar1 = SCT_get_validation_status();
  switch(uVar1) {
  case 0:
    return "not set";
  case 1:
    return "unknown log";
  case 2:
    return "valid";
  case 3:
    return "invalid";
  case 4:
    return "unverified";
  case 5:
    return "unknown version";
  default:
    return "unknown status";
  }
}

