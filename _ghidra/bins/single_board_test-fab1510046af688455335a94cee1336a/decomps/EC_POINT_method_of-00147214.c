
EC_METHOD * EC_POINT_method_of(EC_POINT *point)

{
  return *(EC_METHOD **)point;
}

