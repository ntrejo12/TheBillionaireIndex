#define CROW_MAIN
#define ASIO_STANDALONE
#include <iostream>
#include "include/crow.h"
#include "billionaire.h"
#include "merge.h"
#include "heap.h"
using namespace std;

struct CORS {
    struct context {};
    void before_handle(crow::request& req, crow::response& res, context&) {
        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.add_header("Access-Control-Allow-Headers", "Content-Type");
    }
    void after_handle(crow::request& req, crow::response& res, context&) {}
};
int main()
{
    crow::App<CORS> app;

    CROW_ROUTE(app, "/")([](){
        return "Crow is working!";
    });

    CROW_ROUTE(app, "/top-billionaires").methods("OPTIONS"_method)([](){
        return "";
    });


    CROW_ROUTE(app, "/top-billionaires")([](const crow::request& req){
        string year = req.url_params.get("year") ? req.url_params.get("year") : "";
        string kStr = req.url_params.get("k") ? req.url_params.get("k") : "5";
        int k = stoi(kStr);
        string filename = "billionaire_list_20yrs.csv";

        auto result = finalMergeAsJSON(filename, year, k);
        crow::response res(result);

        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.add_header("Access-Control-Allow-Headers", "Content-Type");

        return res;
});

    CROW_ROUTE(app, "/heap-duration")([](const crow::request& req){
        string year = req.url_params.get("year") ? req.url_params.get("year") : "";
        string kStr = req.url_params.get("k") ? req.url_params.get("k") : "5";
        int k = stoi(kStr);
        string filename = "billionaire_list_20yrs.csv";

        auto result = heapSortDurationAsJSON(filename, year, k);
        crow::response res(result);

        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.add_header("Access-Control-Allow-Headers", "Content-Type");

        return res;
});


    app.port(18080).run();
}
