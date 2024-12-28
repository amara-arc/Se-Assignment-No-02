

#include <iostream>
#include <string>
using namespace std;


class Meadow
{
private:
    static Meadow* instance;
    Meadow() {}
public:
    static Meadow* getInstance()
     {
        if (!instance)
            {
            instance = new Meadow();
        }
        return instance;
    }
    void spawnAntFarm(const string& species)
     {
        cout << "Spawning an ant farm with species: " << species << endl;
    }
};
Meadow* Meadow::instance = nullptr;


class Ant
{
public:
    virtual void action() = 0;
    virtual ~Ant() {}
};


class Worker : public Ant
 {
public:
    void action() override
    {
        cout << "Worker ant is foraging for food." << endl;
    }
};

class Warrior : public Ant
{
public:
    void action() override
     {
        cout << "Warrior ant is patrolling and fighting." << endl;
    }
};


class AntFactory
{
public:
    static Ant* createAnt(const string& type)
    {
        if (type == "Worker")
            {
            return new Worker();
        }
        else if (type == "Warrior")
            {
            return new Warrior();
        } else
        {
            throw invalid_argument("Unknown ant type!");
        }
    }
};


class AntDecorator : public Ant
{
protected:
    Ant* wrappedAnt;
public:
    AntDecorator(Ant* ant)
    {
        wrappedAnt=ant;
    }
    void action() override
     {
        wrappedAnt->action();
    }
    ~AntDecorator()
    {
        delete wrappedAnt;
    }
};

 class StrongAnt : public AntDecorator {
public:
    StrongAnt(Ant* ant) : AntDecorator(ant) {}
    void action() override {
        cout << "[Strong] ";
        wrappedAnt->action();
    }
};

 class EfficientAnt : public AntDecorator {
public:
    EfficientAnt(Ant* ant) : AntDecorator(ant) {}
    void action() override {
        cout << "[Efficient] ";
        wrappedAnt->action();
    }
};


class AntFarm
 {
private:
    string species;
    int workers;
    int warriors;
public:
     AntFarm(const string& species) : species(species), workers(0), warriors(0) {}


    void addWorker()
    {
        workers++;
        cout << "Added a worker to the " << species << " farm." << endl;
    }

    void addWarrior()
    {
        warriors++;
        cout << "Added a warrior to the " << species << " farm." << endl;
    }

    void summary()
    {
        cout << "Species: " << species << ", Workers: " << workers << ", Warriors: " << warriors << endl;
    }
};

class AntFarmBuilder
{
private:
    AntFarm* farm;
public:
    AntFarmBuilder(const string& species)
    {
        farm = new AntFarm(species);
    }

    void addWorkers(int count)
    {
        for (int i = 0; i < count; ++i)
            {
            farm->addWorker();
        }
    }

    void addWarriors(int count)
    {
        for (int i = 0; i < count; ++i)
            {
            farm->addWarrior();
        }
    }

    AntFarm* getFarm()
     {
        return farm;
    }
};


class SimulationMediator
{
private:
    AntFarm* farm1;
    AntFarm* farm2;
public:
    SimulationMediator()
    {
        farm1=nullptr;
        farm2=nullptr;
    }
    void addAntFarm(AntFarm* farm, int slot)
     {
        if (slot == 1)
            {
            farm1 = farm;
        }
        else if (slot == 2)
         {
            farm2 = farm;
        }
    }
    void tick()
     {
        cout << "Ticking simulation..." << endl;
        if (farm1) farm1->summary();
        if (farm2) farm2->summary();
    }
};


int main()
{

    Meadow* meadow = Meadow::getInstance();
    meadow->spawnAntFarm("Killer");


    AntFarmBuilder builder1("Killer");
    builder1.addWorkers(3);
    builder1.addWarriors(2);
    AntFarm* farm1 = builder1.getFarm();

    AntFarmBuilder builder2("Gatherer");
    builder2.addWorkers(5);
    builder2.addWarriors(1);
    AntFarm* farm2 = builder2.getFarm();


    SimulationMediator mediator;
    mediator.addAntFarm(farm1, 1);
    mediator.addAntFarm(farm2, 2);


    cout << "Simulation Tick 1:" << endl;
    mediator.tick();

    return 0;
}
