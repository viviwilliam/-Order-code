import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.*;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.sql.*;

public class MainScene extends Application {
    public String URL="jdbc:mysql://localhost:3306/carsbase?useUnicode=true&characterEncoding=utf8&serverTimezone=GMT";
    public String NAME = "root";
    public String PASSWORD="wwl133933";

    public static void main(String[] args){
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        BorderPane root = new BorderPane();
        GridPane hbox = new GridPane();
        //顶部文本
        Text title = new Text();
        title.setCache(true);
        title.setFont(Font.font(null, FontWeight.BOLD, 32));
        title.setText("用户登录");
        hbox.addRow(0,title);
        hbox.setAlignment(Pos.CENTER);



        TextField login = new TextField();

        TextField password = new TextField();

        GridPane centerPane = new GridPane();
        centerPane.add(new Label("姓名"),0,0);
        centerPane.add(login,1,0);
        centerPane.add(new Label("密码"),0,1);
        centerPane.add(password,1,1);



        Button bt1 = new Button("登陆");
        centerPane.add(bt1,1,2);

        centerPane.setAlignment(Pos.CENTER);

        root.setTop(hbox);
        root.setCenter(centerPane);



        Scene scene = new Scene(root,400,400);
        primaryStage.setScene(scene);
        primaryStage.show();

        bt1.setOnAction(e-> {
            try {
                checkData(login.getText(),password.getText(),primaryStage);
            } catch (SQLException ex) {
                ex.printStackTrace();
            } catch (ClassNotFoundException ex) {
                ex.printStackTrace();
            }
        });
    }
    //读取数据库的账号密码
    public int readData(String id,String pass) throws ClassNotFoundException, SQLException {

        //1.加载驱动程序
        Class.forName("com.mysql.cj.jdbc.Driver");
        //2.获得数据库的连接
        Connection conn = DriverManager.getConnection(URL, NAME, PASSWORD);
        //3.通过数据库的连接操作数据库，实现增删改查
        Statement stmt = conn.createStatement();
        ResultSet rs = stmt.executeQuery("select id,name,password from users");//选择import java.sql.ResultSet;
        while(rs.next()){//如果对象中有数据，就会循环打印出来
            if(id.equals(rs.getString("name"))&&pass.equals(rs.getString("password"))){
                return rs.getInt("id");
            }
        }
        return 0;

    }


    public void addshow(GridPane centerPane, String id) throws Exception{
        //1.加载驱动程序
        Class.forName("com.mysql.cj.jdbc.Driver");
        //2.获得数据库的连接
        Connection conn = DriverManager.getConnection(URL, NAME, PASSWORD);
        //3.通过数据库的连接操作数据库，实现增删改查
        Statement stmt = conn.createStatement();
        ResultSet rs2 = null;
        rs2 = stmt.executeQuery("select id,carsid,data from rentRecord");
        int i=2;
        while(true){
            if (!rs2.next())
                break;
            if(id.equals(rs2.getString("id"))){
                centerPane.add(new Text("车牌:"),0,i);
                centerPane.add(new Text("时间:"),2,i);
                centerPane.add(new Text(rs2.getString("carsid")),1,i);
                centerPane.add(new Text(rs2.getString("data")),3,i);
                i++;
            }
        }
    }

    public void userMannage() throws Exception{
        Stage usermannage = new Stage();
        BorderPane show = new BorderPane();
        TextField search = new TextField();
        Button apply = new Button("查询");
        GridPane topPane = new GridPane();
        topPane.add(new Label("Name"),0,0);
        topPane.add(search,1,0);
        topPane.add(apply,2,0);
        topPane.setAlignment(Pos.CENTER);
        show.setTop(topPane);

        GridPane centerPane = new GridPane();
        Text t1 = new Text("Name:");
        Text t2 = new Text("Password:");
        centerPane.add(t1,0,0);
        centerPane.add(t2,0,1);
        centerPane.setAlignment(Pos.CENTER);
        show.setCenter(centerPane);


        Scene scene = new Scene(show,800,800);
        usermannage.setScene(scene);
        usermannage.show();
        apply.setOnAction(e->{
            //1.加载驱动程序
            try {
                Class.forName("com.mysql.cj.jdbc.Driver");
            } catch (ClassNotFoundException ex) {
                ex.printStackTrace();
            }
            //2.获得数据库的连接
            Connection conn = null;
            try {
                conn = DriverManager.getConnection(URL, NAME, PASSWORD);
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
            //3.通过数据库的连接操作数据库，实现增删改查
            Statement stmt = null;
            try {
                stmt = conn.createStatement();
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
            ResultSet rs = null;//选择import java.sql.ResultSet;
            try {
                rs = stmt.executeQuery("select id,name,password from users");
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
            while(true){
                try {
                    if (!rs.next()) break;
                } catch (SQLException ex) {
                    ex.printStackTrace();
                }//如果对象中有数据，就会循环打印出来
                try {
                    if(search.getText().equals(rs.getString("name"))){
                        Text t3 = new Text(rs.getString("name"));
                        Text t4 = new Text(rs.getString("password"));
                        centerPane.add(t3,1,0);
                        centerPane.add(t4,1,1);
                        addshow(centerPane,rs.getString("id"));
                        break;

                    }
                } catch (SQLException ex) {
                    ex.printStackTrace();
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        });
    }

    public void changeCar(String id,String bra,int maney,String typ) throws Exception{
        //1.加载驱动程序
        Class.forName("com.mysql.cj.jdbc.Driver");
        //2.获得数据库的连接
        Connection conn = DriverManager.getConnection(URL, NAME, PASSWORD);
        //3.通过数据库的连接操作数据库，实现增删改查

        ResultSet rs2 = null;
        String sql="update cars set brand=?,preRent=?,type=? where id = ?";
        PreparedStatement ps = conn.prepareStatement(sql);
        ps.setString(1, bra);
        ps.setInt(2, maney);
        ps.setString(3, typ);
        ps.setString(4, id);
        int resultSet=ps.executeUpdate();

        if(resultSet>0){
            Stage alert = new Stage();
            BorderPane show = new BorderPane();
            Text massage = new Text("修改成功！");
            show.setCenter(massage);
            Scene scene = new Scene(show,200,100);
            alert.setScene(scene);
            alert.show();
        }else{
            Stage alert = new Stage();
            BorderPane show = new BorderPane();
            Text massage = new Text("修改失败！");
            show.setCenter(massage);
            Scene scene = new Scene(show,200,100);
            alert.setScene(scene);
            alert.show();
        }
    }



    public void addCar(String id,String bra,int maney,String typ) throws Exception{
        //1.加载驱动程序
        Class.forName("com.mysql.cj.jdbc.Driver");
        //2.获得数据库的连接
        Connection conn = DriverManager.getConnection(URL, NAME, PASSWORD);
        //3.通过数据库的连接操作数据库，实现增删改查

        ResultSet rs2 = null;
        String sql="insert into cars (id,brand,preRent,type) values (?,?,?,?)";
        PreparedStatement ps = conn.prepareStatement(sql);
        ps.setString(1, id);
        ps.setString(2, bra);
        ps.setInt(3, maney);
        ps.setString(4, typ);
        int resultSet=ps.executeUpdate();

        if(resultSet>0){
            Stage alert = new Stage();
            BorderPane show = new BorderPane();
            Text massage = new Text("插入成功！");
            show.setCenter(massage);
            Scene scene = new Scene(show,200,100);
            alert.setScene(scene);
            alert.show();
        }else{
            Stage alert = new Stage();
            BorderPane show = new BorderPane();
            Text massage = new Text("插入失败！");
            show.setCenter(massage);
            Scene scene = new Scene(show,200,100);
            alert.setScene(scene);
            alert.show();
        }
    }


    public void DeleCar(String id) throws Exception{
        //1.加载驱动程序
        Class.forName("com.mysql.cj.jdbc.Driver");
        //2.获得数据库的连接
        Connection conn = DriverManager.getConnection(URL, NAME, PASSWORD);
        //3.通过数据库的连接操作数据库，实现增删改查

        ResultSet rs2 = null;
        String sql="delete from cars where id=?";
        PreparedStatement  ps = conn.prepareStatement(sql);
        ps.setString(1,id);
        ps.executeUpdate();

        int resultSet=ps.executeUpdate();

        if(resultSet>0){
            Stage alert = new Stage();
            BorderPane show = new BorderPane();
            Text massage = new Text("删除失败！");
            show.setCenter(massage);
            Scene scene = new Scene(show,200,100);
            alert.setScene(scene);
            alert.show();
        }else{
            Stage alert = new Stage();
            BorderPane show = new BorderPane();
            Text massage = new Text("删除成功！");
            show.setCenter(massage);
            Scene scene = new Scene(show,200,100);
            alert.setScene(scene);
            alert.show();
        }
    }

    public void carMannage() throws Exception{
        BorderPane back = new BorderPane();
        Stage car = new Stage();

        GridPane manner = new GridPane();
        TextField id = new TextField();
        TextField Brand = new TextField();
        TextField password = new TextField();
        TextField type = new TextField();
        TextField money = new TextField();

        TextField id1 = new TextField();
        TextField Brand1 = new TextField();
        TextField password1 = new TextField();
        TextField type1 = new TextField();
        TextField money1 = new TextField();


        TextField DeleId = new TextField();



        GridPane topPane = new GridPane();
        topPane.add(new Label("车牌号"),0,0);
        topPane.add(id,1,0);
        topPane.add(new Label("品牌"),2,0);
        topPane.add(Brand,3,0);
        topPane.add(new Label("型号"),4,0);
        topPane.add(type,5,0);
        topPane.add(new Label("租金"),6,0);
        topPane.add(money,7,0);

        topPane.add(new Label("车牌号"),0,1);
        topPane.add(DeleId,1,1);


        topPane.add(new Label("车牌号"),0,2);
        topPane.add(id1,1,2);
        topPane.add(new Label("品牌"),2,2);
        topPane.add(Brand1,3,2);
        topPane.add(new Label("型号"),4,2);
        topPane.add(type1,5,2);
        topPane.add(new Label("租金"),6,2);
        topPane.add(money1,7,2);




        Button bt1 = new Button("增加");
        topPane.add(bt1,8,0);

        Button bt2 = new Button("删除");
        topPane.add(bt2,8,1);


        Button bt3 = new Button("修改");
        topPane.add(bt3,8,2);
        topPane.setAlignment(Pos.CENTER);
        back.setTop(topPane);

        Scene scene = new Scene(back,1200,800);
        car.setScene(scene);
        car.show();
        bt1.setOnAction(e->{
            try {
                addCar(id.getText(),Brand.getText(),Integer.parseInt(money.getText()),type.getText());
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        });

        bt2.setOnAction(e->{
            try {
                DeleCar(DeleId.getText());
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        });

        bt3.setOnAction(e->{
            try {
                changeCar(id1.getText(),Brand1.getText(),Integer.parseInt(money1.getText()),type1.getText());
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        });
    }

    public void carRender(String ID){
        BorderPane back = new BorderPane();
        Stage car = new Stage();

        GridPane manner = new GridPane();
        TextField id = new TextField();
        TextField Brand = new TextField();
        TextField password = new TextField();
        TextField type = new TextField();
        TextField money = new TextField();

        TextField id1 = new TextField();
        TextField Brand1 = new TextField();
        TextField password1 = new TextField();
        TextField type1 = new TextField();
        TextField money1 = new TextField();


        TextField DeleId = new TextField();
        TextField date = new TextField();
        TextField name = new TextField();
        TextField per = new TextField();

        GridPane topPane = new GridPane();



        //1.加载驱动程序
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
        }
        //2.获得数据库的连接
        Connection conn = null;
        try {
            conn = DriverManager.getConnection(URL, NAME, PASSWORD);
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
        //3.通过数据库的连接操作数据库，实现增删改查
        Statement stmt = null;
        try {
            stmt = conn.createStatement();
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
        ResultSet rs = null;//选择import java.sql.ResultSet;
        try {
            rs = stmt.executeQuery("select name,carsid,data,money from rentRecord");
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
        int i=0;
        while(true){
            try {
                if (!rs.next())
                    break;
            } catch (SQLException ex) {
                ex.printStackTrace();
            }//如果对象中有数据，就会循环打印出来
            try {
                if(rs.getString("name").equals(ID)){
                topPane.add(new Label("租用人"),0,i);
                topPane.add(new Text(rs.getString("name")),1,i);
                topPane.add(new Label("车牌号"),2,i);
                topPane.add(new Text(rs.getString("carsid")),3,i);
                topPane.add(new Label("租用时间"),4,i);
                topPane.add(new Text((rs.getString("data"))),5,i);
                topPane.add(new Label("租金"),6,i);
                topPane.add(new Text(rs.getString("money")),7,i);
                i++;
                }
            } catch (SQLException ex) {
                ex.printStackTrace();
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }

        manner.setAlignment(Pos.CENTER);
        topPane.setAlignment(Pos.CENTER);
        back.setTop(manner);
        back.setCenter(topPane);

        Scene scene = new Scene(back,400,400);
        car.setScene(scene);
        car.setTitle("租借信息");
        car.show();

    }



    public void usermessage(String ID){
        BorderPane back = new BorderPane();
        Stage car = new Stage();

        GridPane manner = new GridPane();
        TextField id = new TextField();
        TextField Brand = new TextField();
        TextField password = new TextField();
        TextField type = new TextField();
        TextField money = new TextField();

        TextField id1 = new TextField();
        TextField Brand1 = new TextField();
        TextField password1 = new TextField();
        TextField type1 = new TextField();
        TextField money1 = new TextField();


        TextField DeleId = new TextField();
        TextField date = new TextField();
        TextField name = new TextField();
        TextField per = new TextField();

        GridPane topPane = new GridPane();



        //1.加载驱动程序
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
        }
        //2.获得数据库的连接
        Connection conn = null;
        try {
            conn = DriverManager.getConnection(URL, NAME, PASSWORD);
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
        //3.通过数据库的连接操作数据库，实现增删改查
        Statement stmt = null;
        try {
            stmt = conn.createStatement();
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
        ResultSet rs = null;//选择import java.sql.ResultSet;
        try {
            rs = stmt.executeQuery("select id,brand,preRent,type from cars");
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
        int i=0;
        while(true){
            try {
                if (!rs.next())
                    break;
            } catch (SQLException ex) {
                ex.printStackTrace();
            }//如果对象中有数据，就会循环打印出来
            try {

                topPane.add(new Label("车牌号"),0,i);
                topPane.add(new Text(rs.getString("id")),1,i);
                topPane.add(new Label("品牌"),2,i);
                topPane.add(new Text(rs.getString("brand")),3,i);
                topPane.add(new Label("型号"),4,i);
                topPane.add(new Text(rs.getString("type")),5,i);
                topPane.add(new Label("租金"),6,i);
                topPane.add(new Text(rs.getString("preRent")),7,i);
                i++;
            } catch (SQLException ex) {
                ex.printStackTrace();
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }

        manner.add(new Label("车牌号"),0,0);
        manner.add(DeleId,1,0);

        manner.add(new Label("品牌"),2,0);
        manner.add(name,3,0);

        manner.add(new Label("租金"),4,0);
        manner.add(per,5,0);

        manner.add(new Label("时间"),6,0);
        manner.add(date,7,0);




        Button bt1 = new Button("租借");
        manner.add(bt1,8,0);

        manner.setAlignment(Pos.CENTER);
        topPane.setAlignment(Pos.CENTER);
        back.setTop(manner);
        back.setCenter(topPane);

        Scene scene = new Scene(back,1200,800);
        car.setScene(scene);
        car.show();
        bt1.setOnAction(e->{
            try {
                addRent(DeleId.getText(),ID,name.getText(),Integer.parseInt(date.getText()),Integer.parseInt(per.getText()));
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        });

    }
    public void addRent(String ID,String name,String brand,int days,int pre) throws Exception{
        double money =0;
        if(brand=="宝马"||brand=="奥迪"){
            if(days >0 && days <= 7) {
                //days小于7天，不打折
                money = pre*days;
            }else if (days > 7 && days <= 30) {
                //days大于7天，9折
                money = pre*days*0.9;
            }else if (days > 30 && days <= 150) {
                //days大于30天，8折
                money = pre*days*0.8;
            }else if (days > 150) {
                //days大于150天，7折
                money = pre*days*0.7;
            }
        }
        else{
            if(days >0 && days <3) {
                //days小于3天，不打折
                money = pre*days;
            }else if (days >= 3 && days < 7) {
                //days大于3天，9折
                money = pre*days*0.9;
            }else if (days >= 7 && days <30) {
                //days大于7天，8折
                money = pre*days*0.8;
            }else if (days >= 30 && days <150) {
                //days大于30天，7折
                money = pre*days*0.7;
            }else if (days >= 150) {
                //days大于150天，6折
                money = pre*days*0.6;
            }
        }

        //1.加载驱动程序
        Class.forName("com.mysql.cj.jdbc.Driver");
        //2.获得数据库的连接
        Connection conn = DriverManager.getConnection(URL, NAME, PASSWORD);
        //3.通过数据库的连接操作数据库，实现增删改查

        ResultSet rs2 = null;
        String sql="insert into rentRecord (name,carsid,data,money) values (?,?,?,?)";
        PreparedStatement ps = conn.prepareStatement(sql);
        ps.setString(1, name);
        ps.setString(2, ID);
        ps.setInt(3, days);
        ps.setDouble(4, money);
        int resultSet=ps.executeUpdate();

        if(resultSet>0){
            Stage alert = new Stage();
            BorderPane show = new BorderPane();
            Text massage = new Text("租借成功！");
            show.setCenter(massage);
            Scene scene = new Scene(show,200,100);
            alert.setScene(scene);
            alert.show();
        }else{
            Stage alert = new Stage();
            BorderPane show = new BorderPane();
            Text massage = new Text("租借失败！");
            show.setCenter(massage);
            Scene scene = new Scene(show,200,100);
            alert.setScene(scene);
            alert.show();
        }
    }


    public void checkData(String ID,String password,Stage primaryStage ) throws SQLException, ClassNotFoundException {
        System.out.println(readData(ID,password));
        //经理界面，查看用户信息，增加/修改/删除车辆信息以及租金
        //
        if(readData(ID,password)==0){
            Stage alert = new Stage();
            BorderPane show = new BorderPane();
            Text massage = new Text("用户名或密码错误！");
            show.setCenter(massage);
            Scene scene = new Scene(show,200,100);
            alert.setScene(scene);
            alert.show();

        }

        else if(readData(ID,password)==1){
            BorderPane back = new BorderPane();
            Stage user = new Stage();
            GridPane manner = new GridPane();
            Button bt1 = new Button("查看用户信息");
            Button bt2 = new Button("修改车辆数据");
            manner.add(bt1,0,0);
            manner.add(bt2,0,2);
            manner.setAlignment(Pos.CENTER);
            back.setCenter(manner);

            Scene scene = new Scene(back,400,400);
            user.setScene(scene);
            user.show();
            user.setTitle("经理界面");
            primaryStage.close();
            bt1.setOnAction(e->{
                try {
                    userMannage();
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            });
            bt2.setOnAction(e->{
                try {
                    carMannage();
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            });
        }
        else{
            BorderPane back = new BorderPane();
            Stage user = new Stage();
            GridPane manner = new GridPane();
            Button bt1 = new Button("租车");
            Button bt2 = new Button("查看信息");
            manner.add(bt1,0,0);
            manner.add(bt2,0,2);
            manner.setAlignment(Pos.CENTER);
            back.setCenter(manner);

            Scene scene = new Scene(back,400,400);
            user.setScene(scene);
            user.show();
            user.setTitle("用户界面");
            primaryStage.close();
            bt1.setOnAction(e->{
                try {
                    usermessage(ID);
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            });
            bt2.setOnAction(e->{
                try {
                    carRender(ID);
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            });
        }
    }
}

