# IOT | Interactiviteit voor bever opdracht

## Kermis attractie geinspireerd schietspel

#### Dit onderdeel van de BO opdracht wordt behandeld door Melvin Lockx


### Componentenlijst:

```
> Arduino mega 2560 (Elegoo branded)
> IR Remote control KIT (IR controller 1pc + Receiver 1pc)
> Stepper motor 28BYJ-48
> Draden
> Breadboard
```

### Plannen:

> In totaal wil ik 3 targets maken die elk een eigen IR receiver & stepper motor hebben, de uitdaging hierin ligt het synchroniseren van meerdere IR receivers op 1 Arduino.

> De targets draaien als ze geraakt zijn 180 graden om voor een seconde, en draaien dan weer terug naar hun originele positie.

> De targets zijn gemaakt van hout en hebben een diameter van 10cm.

> De IR afstandsbediening word netjes weggewerkt in een speelgoedachtig geweer.

### UPDATE 20-05-2024:

> Na een aantal online simulaties doordat ik nog niet alle componenten nog heb ben ik erachter gekomen dat IR receivers gecombineerd met een algorithme niet logisch zijn en niet precies genoeg zijn om te werken voor een schietspel.

> Als alternatief discusseer ik nu met mijn groep over het gebruik van een laser en een lichtsensor, of een gyroscopische sensor in het geweer zelf gecombineerd met een ESP32-Module.

> Ook werkt de code nu met een array van stepper motors en is StepperControl.cpp en StepperControl.h aangemaakt voor het schoner werken met de stepper motoren. 
