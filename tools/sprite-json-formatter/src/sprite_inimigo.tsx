<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.10" tiledversion="1.11.0" name="sprite_inimigo" tilewidth="100" tileheight="100" tilecount="10" columns="5">
 <image source="sprite_inimigo.png" width="500" height="200"/>
 <tile id="0">
  <objectgroup draworder="index" id="3">
   <object id="7" x="-100" y="-100" width="300" height="300"/>
   <object id="8" x="28" y="22" width="37" height="42"/>
   <object id="9" x="46" y="42" width="44" height="36"/>
   <object id="10" x="15" y="65" width="22" height="18"/>
  </objectgroup>
 </tile>
 <tile id="1">
  <objectgroup draworder="index" id="2">
   <object id="1" x="61" y="33" width="29" height="44"/>
   <object id="2" x="12" y="7" width="51" height="52"/>
  </objectgroup>
 </tile>
 <tile id="3">
  <objectgroup draworder="index" id="2">
   <object id="1" x="23" y="22" width="23" height="31"/>
   <object id="2" x="65" y="30" width="8" height="32"/>
   <object id="3" x="34" y="73" width="36" height="16"/>
   <object id="4" x="59" y="10" width="51" height="30"/>
   <object id="6" x="54" y="70" width="63" height="54"/>
  </objectgroup>
 </tile>
 <tile id="5">
  <objectgroup draworder="index" id="2">
   <object id="1" x="0" y="0" width="100" height="100"/>
  </objectgroup>
  <animation>
   <frame tileid="0" duration="100"/>
   <frame tileid="1" duration="100"/>
   <frame tileid="2" duration="100"/>
   <frame tileid="3" duration="100"/>
   <frame tileid="4" duration="100"/>
   <frame tileid="5" duration="100"/>
   <frame tileid="6" duration="100"/>
   <frame tileid="7" duration="100"/>
   <frame tileid="8" duration="100"/>
  </animation>
 </tile>
</tileset>
