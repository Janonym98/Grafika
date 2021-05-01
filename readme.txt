First person shooter low budget version készítése.


Szóval eddig az alap betöltését néztem meg... hát a textúrázással még dolgoznom kell... minden jelenleg BETA fázisba van... alakítások és külön objektumokra külön C és H fájlok is lesznek.. ez csak az alap, amiből kiindulok


Szóval elkezdtem folytatni a munkálataimat... jelenleg azzal foglalatoskodtam, hogy egy balloon.h és egy balloon.c fájlt készítsek el... hát igen... problémákba ütköztem, mivel a scene.c-ben betöltött ground objektum betölt, a balloon.c-ben betöltött balloon objektum nem, továbbá a ground.png (scene.c-ben) helyett a cube.png (balloon.c) tölt be be textúrának... tehát a ground objektumra a balloon objektumra szánt textúra tölt be, nem pedig úgy hogy betölt a ground objektum és a ground textúra, betölt a balloon objektum és a balloon textúra (ami a cube.png jelen esetben).


05.01
sikerült megoldani a textúra problémát, viszont a modellt nem tölti be a ballonosat :(

Program futtatása:
Konzolba: make && game
