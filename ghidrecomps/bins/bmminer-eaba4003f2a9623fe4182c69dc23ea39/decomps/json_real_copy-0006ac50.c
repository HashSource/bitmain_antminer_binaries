
json_t * json_real_copy(json_t *real)

{
  json_t *pjVar1;
  double value;
  json_t *real_local;
  
  value = json_real_value(real);
  pjVar1 = json_real(value);
  return pjVar1;
}

