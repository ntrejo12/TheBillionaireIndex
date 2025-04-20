import {useState} from 'react'
import 'bootstrap/dist/css/bootstrap.min.css';
import Example from "./BarChart.jsx";
import './App.css'

function App() {

    return (
        <>
            <div className="outer-box">
                <h1>The Billionaire Index</h1>
                <div className="inner-box">
                    <div className="row g-2">
                        <div className="col-md-4">
                            <label className="form-label">Select Year</label>
                            <select className="form-select">
                                <option selected></option>
                                <option value="1">One</option>
                                <option value="2">Two</option>
                                <option value="3">Three</option>
                            </select>
                        </div>
                        <div className="col-md-4">
                            <label className="form-label">Enter the top # of
                                billionaires
                                to
                                display (k)</label>
                            <input className="form-control"
                                   placeholder=" "/>
                        </div>
                    </div>
                    {/*BAR CHART*/}
                    {/*responsive container adjusts to parents height so it needs to live inside a container*/}
                    {/*with an explicit height*/}
                    <div className="bar-chart" style={{width: '100%', height: 400}}>
                        <Example/>
                    </div>
                    <div className="row g-2 results">
                        <div className="col-md-4">
                            <div className="merge-sort">
                                <div className="sort-inner">
                                    <p>Merge Sort</p>
                                </div>
                            </div>
                        </div>
                        <div className="col-md-4">
                            <div className="heap-sort">
                                <div className="sort-inner">
                                    <p>Heap Sort</p>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </>
    )
}

export default App
