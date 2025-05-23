import React, {useState} from 'react'
import 'bootstrap/dist/css/bootstrap.min.css';
import Example from "./BarChart.jsx";
import './App.css'

function App() {
    const [year, setYear] = useState('');
    const [K, setK] = useState('');

    return (
        <>
            <div className="outer-box">
                <div className="inner-box">
                    <h1>The Billionaire Index</h1>
                    <div className="row g-2">
                        <div className="col-md-4">
                            <label className="form-label">Select Year</label>
                            <select className="form-select"
                                    value={year}
                                    onChange={(event) => setYear(event.target.value)}>
                                <option selected></option>
                                <option value="2002">2002</option>
                                <option value="2003">2003</option>
                                <option value="2004">2004</option>
                                <option value="2005">2005</option>
                                <option value="2006">2006</option>
                                <option value="2007">2007</option>
                                <option value="2008">2008</option>
                                <option value="2009">2009</option>
                                <option value="2010">2010</option>
                                <option value="2011">2011</option>
                                <option value="2012">2012</option>
                                <option value="2013">2013</option>
                                <option value="2014">2014</option>
                                <option value="2015">2015</option>
                                <option value="20116">2016</option>
                                <option value="2017">2017</option>
                                <option value="2018">2018</option>
                                <option value="2019">2019</option>
                                <option value="2020">2020</option>
                                <option value="2021">2021</option>
                                <option value="2022">2022</option>
                                <option value="2023">2023</option>
                            </select>
                        </div>
                        <div className="col-md-4">
                            <label className="form-label"
                            >Enter k</label>
                            <input className="form-control"
                                   value={K}
                                   onChange={(event) => setK(event.target.value)}
                                   placeholder="k"/>
                        </div>
                    </div>
                    {/*BAR CHART*/}
                    {/*responsive container adjusts to parents height so it needs to live inside a container*/}
                    {/*with an explicit height*/}
                    {/*SOURCE: crowbait on github recharts chart title #478*/}
                    <div className="bar-chart">
                        <text x={500 / 2} y={20} fill="black" textAnchor="middle" dominantBaseline="central">
                            <tspan fontSize="20">Top {K || 'K'} Billionaires by Income in {year || '[Year]'}</tspan>
                        </text>
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
