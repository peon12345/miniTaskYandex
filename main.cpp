
int main(int argc, char *argv[])
{

  std::tuple<char,std::pair<char,char> , std::tuple<char,char,char>> num;
  QString numStr = QString::number(sizeof(std::get<0>(num))) + QString::number(sizeof(std::get<1>(num))) + QString::number(sizeof(std::get<2>(num)));

  std::vector<uint> nums = {1,2,123,4,5,6,7,9,10,12,13,11,11,23,11,11,245,246,247,248};
  std::vector<uint>::iterator it = nums.begin();
  std::vector<uint>::iterator oldIt = nums.begin();

  bool rangeStart = false;
  QString resultStr;

  while(it!= nums.end()){

      it = std::adjacent_find(it , nums.end() , [] (uint l , uint r) {return l+1 == r;});

      int distance = std::distance(oldIt,it);

      for(int i =0; i < distance; ++i){

          if( rangeStart){

              rangeStart = false;
              resultStr += QString::number( *(oldIt + i));
              resultStr += ',';
              resultStr += "}";
              continue;
            }

          resultStr += QString::number(*(oldIt + i));
          resultStr += ',';
        }

      if(it != nums.end()){

          if(!rangeStart){
              resultStr += "{";
              rangeStart = true;
            }

          resultStr +=QString::number( *it);
          resultStr += ',';
          ++it;
          oldIt = it;
        }

    }
  qDebug() << resultStr;

  //"{1,2,}123,{4,5,6,7,}{9,10,}{12,13,}11,11,23," output

  return 0;

}













