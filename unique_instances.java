import java.util.*;

class Customers {
  String name;
  int purchasedCount;
  static HashMap<String, Integer> customers_list = new HashMap<>();

  Customers(String name, int purchasedCount) {
    this.name = name;
    this.purchasedCount = purchasedCount;
  }

  public static void add(Customers customer) {
    if (customers_list.containsKey(customer.name)) {
      System.out.println("Updated existing record");
    } else {
      System.out.println("Adding new record");
    }
    customers_list.put(customer.name, customer.purchasedCount);
    System.out.println(customer.name + " " + customer.purchasedCount);
  }
}

class unique_instances {
  public static void main(String[] args) {
    Customers.add(new Customers("A", 1));
    Customers.add(new Customers("B", 2));
    Customers.add(new Customers("C", 3));
    Customers.add(new Customers("A", 2));
    System.out.println(Customers.customers_list);
  }
  
}
