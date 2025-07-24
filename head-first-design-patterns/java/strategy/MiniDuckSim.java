public class MiniDuckSim {

    public static void main(String[] args) {
        
        Duck mallard = new MallardDuck();
        mallard.performFly();
        mallard.performQuack();

        FlyBehavior fb = new FlyNoWay();
        mallard.setFlyBehavior(fb);
        mallard.performFly();

        Duck model = new ModelDuck();
        model.performFly();
        model.setFlyBehavior(new FlyRocketPower());
        model.performFly();
    }
}
