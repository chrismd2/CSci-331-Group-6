//file Record.h

#include "Record.h"

Record::Record()
{
  zip_code = "";
  place_name = "";
  state = "";
  county = "";
  this -> set_longitude_latitude( 0.0, 0.0 );
}

Record::Record(string _zip_code, string _place_name, string _state, string _county, Grid _gridPoint)
{
  zip_code = _zip_code;
  place_name = _place_name;
  state = _state;
  county = _county;
  this -> set_grid_point( _gridPoint );
}

Record::Record(string _zip_code, string _place_name, string _state, string _county, string latitude, string longitude)
{
  float lon = string_to_float( longitude );
  float lat = string_to_float( latitude );

  zip_code = _zip_code;
  place_name = _place_name;
  state = _state;
  county = _county;
  this -> set_longitude_latitude( lon, lat );
}

void Record::display()
{
    cout << endl
       << "Zipcode: " << get_zip_code()
       << " Place: " << get_place_name()
       << " State: " << get_state()
       << " County: " << get_county()
       << " Longitude: " << get_longitude()
       << " Latitude: " << get_latitude()
       << endl;
}

void Record::display(string field)
{
  for(int i = 0; field[i] != NULL; i++){
      field[i] = toupper(field[i]);
  }
  //The following if else-if statements replace the case statement variation
  if(field=="Z" || field=="ZIP")
    cout << zip_code << endl;
  else if(field=="CITY" || field=="P" || field=="PLACE_NAME")
    cout << place_name << endl;
  else if(field=="STATE")
    cout << state << endl;
  else if(field=="COUNTY")
    cout << county << endl;
  else if(field=="G" || field=="GRID")
    cout << gridPoint.getLatitude() << " " << gridPoint.getLongitude() << endl;
  else
    cout << "Invalid field has been entered." << endl;

  
  // switch(field)
  //{
  //   case Z:
  //   case ZIP:
  //     cout << zip_code << endl;
  //     break;
  //   case CITY:
  //   case P:
  //   case PLACE_NAME:
  //     cout << place_name << endl;
  //     break;
  //   case STATE:
  //     cout << state << endl;
  //     break;
  //   case COUNTY:
  //     cout << county << endl;
  //     break;
  //   case G:
  //   case GRID:
  //     cout << gridPoint.getLatitude() << " " << gridPoint.getLongitude() << endl;
  //     break;
  //}
  
}

string Record::get_zip_code()
{
  return zip_code;
}

string Record::get_place_name()
{
  return place_name;
}

string Record::get_state()
{
  return state;
}

string Record::get_county()
{
  return county;
}

float Record::get_latitude()
{
  return gridPoint.getLatitude();
}

float Record::get_longitude()
{
  return gridPoint.getLongitude();
}

Grid Record::get_grid_point()
{
  return gridPoint;
}

void Record::set_zip_code(string _zip_code)
{
  zip_code = _zip_code;
}

void Record::set_place_name(string _place_name)
{
  place_name = _place_name;
}

void Record::set_state(string _state)
{
  state = _state;
}

void Record::set_county(string _county)
{
  county = _county;
}

void Record::set_longitude_latitude(float longitude, float latitude)
{
  gridPoint.setLatitude( latitude );
  gridPoint.setLongitude( longitude );
}

void Record::set_grid_point(Grid _gridPoint)
{
  gridPoint.setLatitude( _gridPoint.getLatitude() );
  gridPoint.setLongitude ( _gridPoint.getLongitude() );
}

//helper functions

float Record::string_to_float(string str)
{
  size_t size;
  float float_value = stof( str, &size );

  return float_value;
}
