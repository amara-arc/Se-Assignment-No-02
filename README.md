Ant Farm Simulation Using Design Patterns
This project implements a simulation of ant farms using various design patterns in C++, including Singleton, Abstract Factory, Decorator, Builder, and Mediator patterns. The system simulates different species of ants, their roles, and the interaction between ant farms, providing a model for understanding how various object-oriented design principles can be applied in a real-world scenario.


Singleton Pattern (Meadow Class):

The Meadow class employs the Singleton Pattern, which ensures that only one instance of the meadow (where ants live and spawn) is available throughout the program .
This pattern eliminates redundant creation of the Meadow instances, thus saving resources and only having central control for simulation of the ant farm.
Abstract Factory Pattern (AntFactory Class):

This factory (AntFactory) creates different types of ants such as Worker and Warrior.
The createAnt() method is used to dynamically create ant objects based on the type, either "Worker" or "Warrior," without having to instantiate them directly, which makes the simulation flexible and scalable.
Decorator Pattern (AntDecorator, StrongAnt, EfficientAnt):

The Decorator Pattern is used to add functionality to the Ant objects without modifying their existing behavior.
Two decorators, StrongAnt and EfficientAnt, are used to wrap around Ant objects, making their actions stronger by prefixing the actions with "[Strong]" and "Efficient" when they execute their activities. This is how behavior can be dynamically added to an object.
Builder Pattern (Class AntFarmBuilder)
Builder Pattern is used to build complex ant farms step-by-step. The AntFarmBuilder allows easy customization of the ant farm by adding a specified number of Workers and Warriors.
It abstracts the building process so that users could be able to make various ant farms with different species and ant types without confronting the complications of object construction.
Mediator Pattern (SimulationMediator Class):
It is implemented by the SimulationMediator that is managing the interaction of many ant farms.
It centralizes communication among various farms, coordinating their simulation tick and showing the status of all ant farms within the simulation, thus they will work together seamlessly without any kind of direct interaction.

Meadow: The simulation begins with the Meadow class, which is the creator and manager of ant farms. The Meadow is a Singleton, meaning only one meadow instance exists, used to spawn different ant farms.

Ant Creation:

The AntFactory class is an Abstract Factory that dynamically creates ant objects such as Worker and Warrior. These ants have different actions, such as foraging for food or patrolling and fighting.
Ant Enhancements:

This gives an ability to the ants to be "decorated" with features like "strength" or "efficiency." For example, StrongAnt is a decorator, enhancing the action of the worker with a strong prefix such as "[Strong] Worker ant is foraging for food."
Ant Farms:
By applying the Builder Pattern, the AntFarmBuilder class creates ant farms through the addition of defined amounts of Worker and Warrior ants. Users can easily adjust these characteristics of each farm.
Simulation:

The SimulationMediator coordinates the simulation between two ant farms. It manages the farms and runs the simulation by calling the tick() method, which prints the status of each farm, showing how many workers and warriors are in each farm.
Output:

The simulation will print out the current state of both ant farms, which contain the number of Worker and Warrior ants in each. The simulation can be extended with further functionality, for example ant interactions or task assignments.
Key Benefits of Using Design Patterns
Scalability: With the Abstract Factory, the system makes it possible to add new ant types, like Scout and Queen, without changing the code already developed.
Flexibility: The Decorator Pattern allows us to add the new behaviors such as strength or efficiency to ants without changing their original behavior.
Separation of Concerns: This Mediator Pattern centralizes the logic for managing all the interactions between different farms of ants, making this simulation more maintainable by preventing direct dependencies between farms.
Ease of Use: The Builder Pattern provides a clear and user-friendly interface for creating customizable ant farms.
Conclusion:
This is how multiple design patterns may be integrated to develop a flexible, maintainable, and scalable simulation. Through the integration of these patterns, it would easily expand and be modified in order to achieve even more complex simulations on the ant behavior, interaction, and management of the ant farm.
