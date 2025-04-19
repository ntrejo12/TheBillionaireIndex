import {useState} from 'react'
import 'bootstrap/dist/css/bootstrap.min.css';
import './App.css'

function App() {
    const [count, setCount] = useState(0)

    const currencies = [
        {
            value: 'USD',
            label: '$',
        },
        {
            value: 'EUR',
            label: '€',
        },
        {
            value: 'BTC',
            label: '฿',
        },
        {
            value: 'JPY',
            label: '¥',
        },
    ];


    return (
        <>
            <div className="outer-box">
                <h1>The Billionaire Index</h1>
                <div className="inner-box">
                    <div className="row g-2">
                        <div className="col-md-4">
                            <label htmlFor="exampleFormControlInput1" className="form-label">Select Year</label>
                            <select className="form-select" aria-label="Default select example">
                                <option selected></option>
                                <option value="1">One</option>
                                <option value="2">Two</option>
                                <option value="3">Three</option>
                            </select>
                        </div>
                        <div className="col-md-4">
                            <label htmlFor="exampleFormControlInput1" className="form-label">Enter the top # of
                                billionaires
                                to
                                display</label>
                            <input type="email" className="form-control" id="exampleFormControlInput1"
                                   placeholder=" "/>
                        </div>
                    </div>
                </div>
            </div>
        </>
    )
}

export default App
